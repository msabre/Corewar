/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:21:10 by msabre            #+#    #+#             */
/*   Updated: 2020/03/05 16:02:54 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

static void			del_dies_cards(t_card **cards, int curr_cycle, int cycles_to_die)
{
	t_card			*tmp;

	while (*cards)
	{
		if (curr_cycle - (*cards)->last_live < 1 || cycles_to_die <= 0)
		{
			tmp = *cards;
			(*cards)->next = *cards;
			free(tmp->regs);
			free(tmp);
		}
		else
			*cards = (*cards)->next;
	}
}

void				check(t_general *all)
{
	if (all->cn_ctd_live >= NBR_LIVE)
		all->ctd -= CYCLE_DELTA;
	if (all->change_cycle == 0)
	{
		all->ctd -= CYCLE_DELTA;
		all->change_cycle = MAX_CHECKS;
	}
	else
		all->change_cycle -= 1;
	all->cn_ctd_live = 0;
	del_dies_cards(&all->cards, all->cycles, all->ctd);
}
