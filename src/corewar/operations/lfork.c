/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:27:24 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_lfork(int card_num, int card_cursor, int adress)
{
	ft_printf("P %4d | lfork %d (%d)\n", card_num, adress,
		card_cursor + adress);
}

void			lfork(t_general *all, t_card *card)
{
	t_card		*new;
	int			adress;
	int			i;

	adress = get_twobytes(all->arena, card->cursor + card->steps);
	card->steps += 2;
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	i = -1;
	while (++i < REG_NUMBER)
		new->regs[i] = card->regs[i];
	new->carry = card->carry;
	new->alive_cycle = card->alive_cycle;
	new->cursor = cursor_to(card->cursor + adress);
	new->next = all->cards;
	new->steps = 0;
	new->player = card->player;
	new->num = all->current_card_num++;
	all->cards = new;
	if (all->flag_v & SHOW_OPERATIONS)
		log_lfork(card->num, card->cursor, adress);
}
