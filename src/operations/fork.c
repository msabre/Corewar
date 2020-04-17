/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:25:40 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/11 17:13:15 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void		log_fork_m(int card_num, int card_cursor, int adress)
{
	ft_printf("P %4d | fork %d (%d)\n", card_num, adress,
		card_cursor + adress % IDX_MOD);
}

void			fork_m(t_general *all, t_card *card)
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
	new->cursor = cursor_to(card->cursor + adress % IDX_MOD);
	new->next = all->cards;
	new->steps = 0;
	new->player = card->player;
	new->num = all->current_card_num++;
	all->cards = new;
	if (all->flag_v & SHOW_OPERATIONS)
		log_fork_m(card->num, card->cursor, adress);
}
