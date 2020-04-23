/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:17:18 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:07:17 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_live(int card_num, int player_num)
{
	ft_printf("P %4d | live %d\n", card_num, -player_num);
}

void			live(t_general *all, t_card *card)
{
	t_player	*player;
	int			value;

	all->n_live_op++;
	card->alive_cycle = all->cycles;
	value = get_fourbytes(all->arena, card->cursor + card->steps);
	card->steps += 4;
	player = NULL;
	if (value * (-1) >= 1 && value * (-1) <= all->n_players)
	{
		player = all->players[value * (-1) - 1];
		all->last_live = player;
	}
	if (all->flag_v & SHOW_OPERATIONS)
		log_live(card->num, -value);
	if (all->flag_v & SHOW_LIVES && player)
		ft_printf("Player %d (%s) is said to be alive\n",
			player->num, player->name);
}
