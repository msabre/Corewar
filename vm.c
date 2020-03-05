/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:25:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/05 17:31:27 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void				lst_free(t_player *lst)
{
	t_player		*ptr;

	while (lst)
	{
		ptr = lst;
		lst = lst->next;
		free(ptr);
	}
}

void				exute_op(t_general *all, t_card *card)
{
	int				tmp;
	int				read_byte;
	int				count_rb;
	int				args[4];
	int				i;
	int				j;

	i = 0;
	j = 0;
	count_rb = 0;
	if (!card->op)
	{
		card->curr_pos += 1;
		return ;
	}
	if (card->code_op)
	{
		read_byte = all->arena.arena[card->curr_pos]; // считываем байт;
		tmp = read_byte;
		while (i < card->op->argc)
		{
			args[i] = (read_byte >> 6) & 3;
			if (args[i++] != card->op->argv[j++])
				break ;
			read_byte = tmp;
		}
	}
}

static t_op		*find_op(t_op **operations, int search, int high)
{
	int			low;
	int			res;
	int			mid;

	low = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		if (operations[mid]->code_op == search)
			return (operations[mid]);
		if (res > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (NULL);
}

static void			check_cards(t_general *all, t_op *operations, t_card *cards, char *arena)
{
	int				res;

	while (cards)
	{
		if (!cards->cycles_to_op)
		{
			exute_op(all, cards); // исполнить операцию
			cards->code_op = ft_atoi(&arena[cards->curr_pos]);
			cards->op = find_op(&operations, cards->code_op, 16);
			if (cards->op)
				cards->cycles_to_op = cards->op->cycles;
		}
		else
			cards->cycles_to_op -= 1;
		cards = cards->next;
	}
}

void				battle(t_general *all)
{
	char			octet;
	int				i;

	while (all->cards) // пока жива хотя бы одна каретка
	{
		if (all->stop_cycle > 0 && all->cycles == all->stop_cycle)
		{
			i = 0;
			while (i < 32) // Распечатка 32 октетов памяти
			{
				octet = next(&all->arena);
				write(1, &(octet), 1);
			}
			return ;
		}
		check_cards(all, all->operations, all->cards, all->arena.arena);
		if (all->cycles % all->ctd == 0) // Прошел 1 cycle_to_die
			check(all);
		all->cycles += 1;
	}
}

int					main(int argc, char **argv)
{
	t_general		all;
	int				i;
	int				j;
	int				fd;

	i = 1;
	j = 0;
	all.players = NULL;
	all.n_players = 0;
	if (argc == 1)
		return (1);
	else
	{
		while (argv[i])
		{

			while (argv[i][j] != '\0')
				j++;
			if (argv[i][j - 4] == '.' && argv[i][j - 3] == 'c' &&
			argv[i][j - 2] == 'o' && argv[i][j - 1] == 'r')
			{
			    fd = open(argv[i], O_RDONLY);
			    valid_check(fd, argc, argv, &(all.players));
			}
			j = 0;
			i++;
		}
	}
	all.n_players = i;
	initial_arena(&all);
	battle(&all);
	return (0);
}
