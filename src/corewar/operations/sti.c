/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:25:08 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_sti(t_card *card, int adress_1, int adress_2, int r)
{
	ft_printf("P %4d | sti r%d %d %d\n", card->num, r, adress_1, adress_2);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		adress_1, adress_2, adress_1 + adress_2,
			card->cursor + ((adress_1 + adress_2) % IDX_MOD));
}

void			sti(t_general *all, t_card *card)
{
	int			adress_1;
	int			adress_2;
	int			adress;
	int			value;
	int			r;

	r = get_nreg(all->arena, card);
	value = card->regs[r];
	adress_1 = get_arg_value(all->arena, card, 1, true);
	adress_2 = get_arg_value(all->arena, card, 2, true);
	adress = (adress_1 + adress_2) % IDX_MOD;
	adress += card->cursor;
	set_reg(all->arena, value, adress);
	if (all->flag_v & SHOW_OPERATIONS)
		log_sti(card, adress_1, adress_2, r + 1);
}
