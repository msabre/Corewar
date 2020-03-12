/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:21:10 by msabre            #+#    #+#             */
/*   Updated: 2020/03/12 13:50:12 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void			del_dies_cards(t_card **cards, int cycle, int cycles_to_die)
{
	t_card			*ptr_cards;
	t_card			*tmp;

	ptr_cards = *cards;
	while (ptr_cards)
	{
		if (cycle - (*cards)->alive_cycle < 1 || cycles_to_die <= 0)
		{
			tmp = *cards;
			(ptr_cards)->next = ptr_cards->next;
			if (tmp == *cards)
				*cards = (*cards)->next;
			free(tmp);
		}
		else
			ptr_cards = ptr_cards->next;
	}
}

void				check(t_general *all)
{
	all->checks_count++;
	if (all->n_live_op >= NBR_LIVE)
	{
		all->ctd -= CYCLE_DELTA;
		all->change_ctd = 1;
	}
	if (all->checks_count == MAX_CHECKS && all->change_ctd == 0)
		all->ctd -= CYCLE_DELTA;
	else
		all->change_ctd -= 1;
	all->n_live_op = 0;
	all->change_ctd = 0;
	del_dies_cards(&all->cards, all->cycles, all->ctd);
}
