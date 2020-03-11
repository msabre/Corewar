/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:21:10 by msabre            #+#    #+#             */
/*   Updated: 2020/03/11 14:56:18 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void			del_dies_cards(t_card **cards, int curr_cycle, int cycles_to_die)
{
	t_card			*ptr_cards;
	t_card			*tmp;

	ptr_cards = *cards;
	while (ptr_cards)
	{
		if (curr_cycle - (*cards)->last_live < 1 || cycles_to_die <= 0)
		{
			tmp = *cards;
			(ptr_cards)->next = ptr_cards->next;
			if (tmp == *cards)
				*cards = (*cards)->next;
			free(tmp->regs);
			free(tmp);
		}
		else
			ptr_cards = ptr_cards->next;
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
