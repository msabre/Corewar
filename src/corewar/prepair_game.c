/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepair_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 21:31:43 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/25 09:13:11 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void		get_op_links(t_general *all)
{
	all->operations[0] = live;
	all->operations[1] = load;
	all->operations[2] = st;
	all->operations[3] = add;
	all->operations[4] = sub;
	all->operations[5] = and;
	all->operations[6] = or;
	all->operations[7] = xor;
	all->operations[8] = zjmp;
	all->operations[9] = ldi;
	all->operations[10] = sti;
	all->operations[11] = fork_m;
	all->operations[12] = lld;
	all->operations[13] = lldi;
	all->operations[14] = lfork;
	all->operations[15] = aff;
}

void		add_card(t_card **cards, t_player *player, int pos)
{
	t_card	*new;

	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	new->carry = false;
	new->regs[0] = player->num * (-1);
	new->next = *cards;
	new->player = player;
	new->num = player->num;
	new->cursor = pos;
	*cards = new;
}

static void	put_execode(t_general *all, t_player **players)
{
	int		mem_start;
	int		shift;
	int		i;

	i = 1;
	set_mem(all->arena, players[0]->exe_code, 0, players[0]->len_exec);
	add_card(&all->cards, players[0], 0);
	shift = MEM_SIZE / all->n_players;
	while (i < all->n_players)
	{
		mem_start = shift * (players[i]->num - 1);
		set_mem(all->arena, players[i]->exe_code, mem_start,
			players[i]->len_exec);
		add_card(&all->cards, players[i], mem_start);
		i++;
	}
}

void		prepare_game(t_general *all)
{
	all->cards = NULL;
	ft_bzero(all->arena, MEM_SIZE);
	put_execode(all, all->players);
	all->ctd = CYCLE_TO_DIE;
	all->cycles = 0;
	all->checks_count = 0;
	all->change_ctd = 0;
	all->last_check = 0;
	all->n_live_op = 0;
	get_op_tab(all);
	get_op_links(all);
	all->last_live = all->cards->player;
	all->current_card_num = all->cards->num + 1;
}
