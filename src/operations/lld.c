/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:26:24 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/08 17:07:29 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void		log_lld(int card_num, int value, int r)
{
	ft_printf("P %4d | lld %d r%d\n", card_num, value, r);
}

void			lld(t_general *all, t_card *card)
{
	int			value;
	int			r;

	value = get_arg_value(all->arena, card, 0, false);
	r = get_nreg(all->arena, card);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? true : false;
	if (all->flag_v & SHOW_OPERATIONS)
		log_lld(card->num, value, r + 1);
}
