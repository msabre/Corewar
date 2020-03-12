/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:25:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/12 14:17:30 by andrejskobe      ###   ########.fr       */
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

static int			is_args_type(t_op *operation)
{
	if (operation->argc == 1 && operation->argv[0] == T_DIR)
		return (0);
	return (1);
}

static int			valid_arg(char my_arg, char valid_arg)
{
	char			a;

	a = my_arg & valid_arg;
	if (a == T_REG && !(a >= 1 && a <= REG_NUMBER))
		return (-1);
	if (a == T_REG || a == T_DIR || a == T_IND)
		return (1);
	return (0);
}

void				check_valid_op(t_general *all, t_card *card, t_op *op)
{
	char			read_byte;
	char			args[4] = {0};
	int				skiplen;
	int				shift;
	int				i;

	i = -1;
	if (!card->op)
		return ;
	read_byte = get_char(&all->arena, card->cursor); // считываем байт;
	if (is_args_type(card->op))
	{
		shift = 6;
		while (++i < card->op->argc)
		{
			args[i] = (read_byte >> shift);
			args[i] &= 3;
			if (!valid_arg(args[i], card->op->argv[i]))
			{
				skiplen = card->cursor + count_skiplen(args, op->argc, op->t_dir_size);
				card->cursor = cursor_to(card->cursor + skiplen);
				return ;
			}
			shift -= 2;
		}
		card->cursor = cursor_next(card->cursor);
	}
	all->operations[card->code_op - 1](all, card, args); // вызов операции
}

static void			check_cards(t_general *all, t_card *cards, unsigned char *arena)
{
	while (cards)
	{
		if (!cards->cycles_to_op)
		{
			check_valid_op(all, cards, cards->op); // исполнить операцию
			cards->code_op = arena[cards->cursor]; // код операции
			cards->cursor = cursor_next(cards->cursor);
			if (cards->code_op >= 1 && cards->code_op <= 16)
			{
				cards->op = &all->op_tab[cards->code_op - 1];
				cards->cycles_to_op = cards->op->cycles; // кол-во циклов до исполнения
			}
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
		check_cards(all, all->cards, all->arena.map);
		if ((all->cycles % all->ctd == 0) || all->ctd <= 0) // Прошел 1 cycle_to_die
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
	prepare_game(&all);
	battle(&all);
	return (0);
}
