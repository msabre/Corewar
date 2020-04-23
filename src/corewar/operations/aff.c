/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:27:44 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 08:52:50 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/corewar.h"

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
