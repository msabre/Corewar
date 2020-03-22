/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:21:10 by msabre            #+#    #+#             */
/*   Updated: 2020/03/22 12:49:20 by andrejskobe      ###   ########.fr       */
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
		if (card->num == 17)
			prev = prev;
		if ((all->cycles - card->alive_cycle) >= all->ctd || all->ctd <= 0)
		{
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
	all->last_check = all->cycles;
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
	del_dies_cards(all);
}
