/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cards.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:38:12 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:13:42 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void	show_cursor_movement(t_general *all, t_card *card)
{
	int		i;

	i = 0;
	ft_printf("ADV %d (0x%.4x -> 0x%.4x) ",
		card->steps, card->cursor, card->cursor + card->steps);
	while (i < card->steps)
	{
		ft_printf("%02x ", get_char(all->arena, card->cursor + i));
		i++;
	}
	write(1, "\n", 1);
}

static void	execute_operations(t_general *all, t_card *card)
{
	card->op = NULL;
	if (card->code_op >= 1 && card->code_op <= 16)
		card->op = &all->op_tab[card->code_op - 1];
	if (card->op)
	{
		check_args_and_exe_op(all, card);
		if (all->flag_v & SHOW_CURSOR_MOVE && card->steps)
			show_cursor_movement(all, card);
	}
	else
		card->steps = 1;
	card->cursor = cursor_move(card);
	card->steps = 0;
}

static void	get_op_code(t_card *card, unsigned char *arena,
			t_op *op_tab)
{
	card->code_op = get_char(arena, card->cursor);
	if (card->code_op >= 1 && card->code_op <= 16)
		card->cycles_to_op = op_tab[card->code_op - 1].cycles;
}

void		check_cards(t_general *all, t_card *cards)
{
	all->cycles++;
	if (all->flag_v & SHOW_CYCLES)
		ft_printf("It is now cycle %d\n", all->cycles);
	while (cards != NULL)
	{
		if (cards->cycles_to_op == 0)
			get_op_code(cards, all->arena, all->op_tab);
		if (cards->cycles_to_op > 0)
			cards->cycles_to_op -= 1;
		if (cards->cycles_to_op == 0)
			execute_operations(all, cards);
		cards = cards->next;
	}
}
