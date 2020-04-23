/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:21:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 08:52:50 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/corewar.h"

static void		log_and(int card_num, int arg_1, int arg_2, int r)
{
	ft_printf("P %4d | and %d %d r%d\n", card_num, arg_1, arg_2, r);
}

void			and(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(all->arena, card, 0, true);
	arg_2 = get_arg_value(all->arena, card, 1, true);
	r = get_nreg(all->arena, card);
	card->regs[r] = arg_1 & arg_2;
	card->carry = (!card->regs[r]) ? true : false;
	if (all->flag_v & SHOW_OPERATIONS)
		log_and(card->num, arg_1, arg_2, r + 1);
}
