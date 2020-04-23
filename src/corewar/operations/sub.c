/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:21:01 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_sub(int card_num, int r1, int r2, int r3)
{
	ft_printf("P %4d | sub r%d r%d r%d\n", card_num, r1, r2, r3);
}

void			sub(t_general *all, t_card *card)
{
	int			r1;
	int			r2;
	int			r3;

	r1 = get_nreg(all->arena, card);
	r2 = get_nreg(all->arena, card);
	r3 = get_nreg(all->arena, card);
	card->regs[r3] = card->regs[r1] - card->regs[r2];
	card->carry = (!card->regs[r3]) ? true : false;
	if (all->flag_v & SHOW_OPERATIONS)
		log_sub(card->num, r1 + 1, r2 + 1, r3 + 1);
}
