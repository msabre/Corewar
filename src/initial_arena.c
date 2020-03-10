/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:19:24 by msabre            #+#    #+#             */
/*   Updated: 2020/03/10 13:19:45 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void				add_card(t_card **cards,int num, int pos)
{
	t_card			*new;
	int				i;

	i = 0;
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	new->regs = (char **)malloc(sizeof(char*) * REG_NUMBER);
	while (i < REG_NUMBER)
	{
		new->regs[i] = (char *)ft_memalloc(sizeof(char) * REG_SIZE);
		if (!new->regs[i])
			exit(-1);
		i++;
	}
	new->num = num;
	if (REG_NUMBER > 0)
	{
		(new)->regs[0][0] = '-';
		(new)->regs[0][1] = num + '0'; // Возможно нужно + '0'
	}
	new->next = *cards;
	if (*cards)
		(*cards)->prev = new;
	*cards = new;
}

static void				put_execode(t_player *players, t_arena *arena, t_card **cards)
{
	int				mem_start;
	int				i;

	i = 1;
	while (players)
	{
		mem_start = (4096 / i);
		set_mem(arena, players->exe_code, mem_start, players->len_exec);
		add_card(cards, i, mem_start);
		players = players->next;
		i++;
	}
}

static void			create_arena(t_arena *arena)
{
	arena->map = (char *)ft_memalloc(sizeof(char) * (4096 + 1));
	if (!arena->map)
		exit(-1);
	arena->get = get;
	arena->next = next;
	arena->set_byte = set_byte;
	arena->set_mem = set_mem;
	arena->ind = 0;
}

void				initial_arena(t_general *all)
{
	t_player		*tmp;

	tmp = all->players;
	all->cards = NULL;
	create_arena(&all->arena);
	put_execode(all->players, &all->arena, &all->cards);
	all->ctd = CYCLE_TO_DIE;
	all->cycles = 1;
	all->cn_ctd_live = 0;
	create_op_tab(all);
	while (tmp->next)
		tmp = tmp->next;
	all->last_live = tmp;
}
