/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:21:10 by msabre            #+#    #+#             */
/*   Updated: 2020/04/07 17:11:28 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void			del_dies_cards(t_general *all)
{
	t_card			*card;
	t_card			*prev;
	t_card			*tmp;

	card = all->cards;
	prev = NULL;
	while (card)
	{
		if ((all->cycles - card->alive_cycle) >= all->ctd || all->ctd <= 0)
		{
			if (all->flag_v & SHOW_DEATHS)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					card->num, all->cycles - card->alive_cycle, all->ctd);
			tmp = card;
			card = card->next;
			if (prev)
				prev->next = card;
			if (tmp == all->cards)
				all->cards = card;
			free(tmp);
		}
		else
		{
			prev = card;
			card = card->next;
		}
	}
}

void				check(t_general *all)
{
	all->checks_count++;
	del_dies_cards(all);
	all->last_check = all->cycles;
	if (all->checks_count == MAX_CHECKS || all->n_live_op >= NBR_LIVE)
	{
		all->ctd -= CYCLE_DELTA;
		all->checks_count = 0;
		if (all->flag_v & SHOW_CYCLES)
			ft_printf("Cycle to die is now %d\n", all->ctd);
	}
	else
		all->change_ctd -= 1;
	all->n_live_op = 0;
	all->change_ctd = 0;
}
