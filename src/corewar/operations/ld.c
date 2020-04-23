/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:18:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_load(int card_num, int value, int r)
{
	ft_printf("P %4d | ld %d r%d\n", card_num, value, r);
}

void			load(t_general *all, t_card *card)
{
	int			value;
	int			r;

	value = get_arg_value(all->arena, card, 0, true);
	r = get_nreg(all->arena, card);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? true : false;
	if (all->flag_v & SHOW_OPERATIONS)
		log_load(card->num, value, r + 1);
}
