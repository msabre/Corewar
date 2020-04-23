/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:23:15 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:15:10 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_xor(int card_num, int arg_1, int arg_2, int r)
{
	ft_printf("P %4d | xor %d %d r%d\n", card_num, arg_1, arg_2, r);
}

void			xor(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(all->arena, card, 0, true);
	arg_2 = get_arg_value(all->arena, card, 1, true);
	r = get_nreg(all->arena, card);
	card->regs[r] = arg_1 ^ arg_2;
	card->carry = (!card->regs[r]) ? true : false;
	if (all->flag_v & SHOW_OPERATIONS)
		log_xor(card->num, arg_1, arg_2, r + 1);
}
