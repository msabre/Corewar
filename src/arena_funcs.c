/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:16:57 by msabre            #+#    #+#             */
/*   Updated: 2020/03/07 14:11:54 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char				next(t_arena *arena)
{
	if (arena->ind > 4095)
		arena->ind %= 4095;
	return (arena->map[arena->ind]);
}

char				get(t_arena *arena, int num)
{
	if (num > 4095)
		num %= 4095;
	return (arena->map[num]);
}

void				set_byte(t_arena *arena, char byte, int num)
{
	if (num > 4095)
		num %= 4095 + 1;
	arena->map[num] = byte;
}

void				set_mem(t_arena *arena, char *mem, int num, int size)
{
	int				i;

	i = 0;
	while (mem && i < size)
		set_byte(arena, mem[i++], num++);
}
