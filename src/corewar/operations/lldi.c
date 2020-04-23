/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:26:45 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_lldi(t_card *card, int adress_1, int adress_2, int r)
{
	ft_printf("P %4d | lldi %d %d r%d\n", card->num, adress_1, adress_2, r);
	ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		adress_1, adress_2, adress_1 + adress_2,
			card->cursor + adress_1 + adress_2);
}

void			lldi(t_general *all, t_card *card)
{
	int			adress_1;
	int			adress_2;
	int			adress;
	int			r;

	adress_1 = get_arg_value(all->arena, card, 0, true);
	adress_2 = get_arg_value(all->arena, card, 1, true);
	adress = adress_1 + adress_2;
	adress += card->cursor;
	r = get_nreg(all->arena, card);
	card->regs[r] = (unsigned int)get_fourbytes(all->arena, adress);
	card->carry = (!card->regs[r]) ? true : false;
	if (all->flag_v & SHOW_OPERATIONS)
		log_lldi(card, adress_1, adress_2, r + 1);
}
