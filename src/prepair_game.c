/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepair_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:19:24 by msabre            #+#    #+#             */
/*   Updated: 2020/03/23 11:40:29 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void				add_card(t_card **cards, t_player *player, int pos)
{
	t_card			*new;
	int				i;

	i = 0;
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	new->regs[0] = player->num * (-1);
	new->next = *cards;
	new->player = player;
	new->num = player->num;
	*cards = new;
}

static void			put_execode(t_player *players, t_arena *arena, t_card **cards)
{
	int				mem_start;

	set_mem(arena, players->exe_code, 0, players->len_exec);
	add_card(cards, players, 0);
	players = players->next;
	while (players)
	{
		mem_start = (MEM_SIZE / players->num) - 1;
		set_mem(arena, players->exe_code, mem_start, players->len_exec);
		add_card(cards, players, mem_start);
		players = players->next;
	}
}

void				prepare_game(t_general *all)
{
	all->cards = NULL;
	all->arena.ind = 0;
	ft_bzero(all->arena.map, MEM_SIZE);
	put_execode(all->players, &all->arena, &all->cards);
	all->ctd = CYCLE_TO_DIE;
	all->cycles = 0;
	all->flag_v = 1;
	all->checks_count = 0;
	all->change_ctd = 0;
	all->n_live_op = 0;
	get_op_tab(all);
	get_op_links(all);
	all->last_live = all->cards->player;
	all->current_card_num = all->cards->num + 1;
}
