/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:25:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/08 12:09:51 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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

static void			execute_op(t_general *all, t_card *card, char *args, int count)
{
	if (card->op->code_op == 1)
		live(all, card,  args);
	if (card->op->code_op == 11)
		sti(all, card, args);
}

static int			skip_op_code(t_op *operation)
{
	int				skip_bytes;
	int				i;

	i = 0;
	skip_bytes = 0;
	while (i < operation->argc)
	{
		if (operation->argv[i] == T_DIR)
			skip_bytes += operation->t_dir_size;
		else if (operation->argv[i] == T_REG)
			skip_bytes += 1;
		else if (operation->argv[i] == T_IND)
			skip_bytes += 2;
		i++;
	}
	return (skip_bytes);
}

static int			is_args_type(t_op *operation)
{
	if (operation->argc == 1 && operation->argv[0] == 2)
		return (0);
	return (1);
}

static int			valid_arg(char my_arg, char valid_arg)
{
	char			a;

	a = my_arg & valid_arg;
	if (a == T_DIR || a == T_IND || a == T_REG)
		return (1);
	return (0);
}

void				check_valid_op(t_general *all, t_card *card)
{
	char			read_byte;
	int				count_rb;
	char			args[4];
	int				div;
	int				i;
	int				j;

	i = 0;
	j = 0;
	count_rb = 0;
	if (!card->op)
		return ;
	if (card->code_op)
	{
		read_byte = all->arena.map[card->curr_pos]; // считываем байт;
		if (is_args_type(card->op))
		{
			div = 6;
			while (i < card->op->argc)
			{
				args[i] = (read_byte >> div);
				args[i] &= 3;
				if (!valid_arg(args[i++], card->op->argv[j++]))
				{
					card->curr_pos += skip_op_code(card->op) + 1; // +1 байт хранящий код типов аргументов
					return ;
				}
				div -= 2;
			}
			card->curr_pos += 1; // переключаемся на аргументы
		}
		execute_op(all, card, args, i);
	}
}

static t_op			*find_op(t_op *operations, int search, int high)
{
	int				low;
	int				res;
	int				mid;

	low = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		if (operations[mid].code_op == search)
			return (&operations[mid]);
		if (search < operations[mid].code_op)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (NULL);
}

static void			check_cards(t_general *all, t_op *operations, t_card *cards, char *arena)
{
	while (cards)
	{
		if (!cards->cycles_to_op)
		{
			check_valid_op(all, cards); // исполнить операцию
			cards->code_op = arena[cards->curr_pos++]; // код операции
			cards->op = find_op(operations, cards->code_op, 16); // Передает указатель на операцию в случае нахождения
			if (cards->op)
				cards->cycles_to_op = cards->op->cycles; // кол-во циклов до исполнения
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
		check_cards(all, all->op, all->cards, all->arena.map);
		if (all->cycles % all->ctd == 0) // Прошел 1 cycle_to_die
			check(all);
		all->cycles += 1;
	}
}

int					main(int argc, char **argv)
{
	t_general		all;
	all.players = NULL;
	all.n_players = 0;
	all.stop_cycle = 0;
	all.flag_n = 0;
	if (argc == 1)
		return (1);
	else
		read_player(argv, &all);
	initial_arena(&all);
	battle(&all);
	return (0);
}
