/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:19:24 by msabre            #+#    #+#             */
/*   Updated: 2020/03/05 17:30:46 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

static void			add_card(t_card **cards,int num, int pos)
{
	t_card			*new;

	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	new->regs = (int *)ft_memalloc(sizeof(int) * REG_NUMBER);
	new->num = num;
	new->next = *cards;
	if (REG_NUMBER > 0)
		new->regs[0] = num;
	(*cards)->prev = new;
	*cards = new;
}

static void				put_execode(t_player *players, t_arena *arena, t_card *cards)
{
	int				mem_start;
	int				i;

	i = 1;
	while (players)
	{
		mem_start = (4095 / i) + 1;
		set_mem(arena, players->exe_code, mem_start, players->len_exec);
		add_card(&cards, i, mem_start);
		players = players->next;
		i++;
	}
}

static void			create_arena(t_arena *arena)
{
	arena->arena = (char *)ft_memalloc(sizeof(char) * (4096 + 1));
	if (!arena->arena)
		exit(-1);
	arena->get = get;
	arena->next = next;
	arena->set_byte = set_byte;
	arena->set_mem = set_mem;
}

void				initial_arena(t_general *all)
{
	t_player		*tmp;

	tmp = all->players;
	create_arena(&all->arena);
	put_execode(all->players, &all->arena, all->cards);
	all->ctd = CYCLE_TO_DIE;
	all->cycles = 1;
	all->cn_ctd_live = 0;
	while (tmp->next)
		tmp = tmp->next;
	all->last_live = tmp;
}
