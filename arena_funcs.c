/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:16:57 by msabre            #+#    #+#             */
/*   Updated: 2020/03/05 17:25:02 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

char				next(t_arena *arena)
{
	if (arena->ind > 4095)
		arena->ind %= 4095;
	return (arena->arena[arena->ind]);
}

char				get(t_arena *arena, int num)
{
	if (num > 4095)
		num %= 4095;
	return (arena->arena[num]);
}

void				set_byte(t_arena *arena, char byte, int num)
{
	if (num > 4095)
		num %= 4095 + 1;
	arena->arena[num] = byte;
}

void				set_mem(t_arena *arena, char *mem, int num, int size)
{
	int				i;

	i = 0;
	while (mem && mem[i] && i < size)
		set_byte(arena, mem[i++], num++);
}
