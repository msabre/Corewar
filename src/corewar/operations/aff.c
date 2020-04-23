/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:27:44 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void			aff(t_general *all, t_card *card)
{
	int			r;
	int			value;

	r = get_char(all->arena, card->cursor + card->steps) - 1;
	card->steps += 1;
	value = card->regs[r];
	if (all->aff_key || all->flag_v & SHOW_OPERATIONS)
		ft_printf("Aff: %c\n", value);
}
