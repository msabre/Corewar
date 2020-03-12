/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:16:57 by msabre            #+#    #+#             */
/*   Updated: 2020/03/12 14:14:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char				next(t_arena *arena)
{
	if (arena->ind > 4095)
		arena->ind %= 4096;
	return (arena->map[arena->ind]);
}

char				get_char(t_arena *arena, int num)
{
	if (num > 4095)
		num %= 4096;
	return (arena->map[num]);
}

int					get_bytes(t_arena *arena, int start, int size)
{
	int				value;
	int				i;

	i = 0;
	value = 0;
	while (i < size)
	{
		value += get_char(arena, start++);
		i++;
	}
	return (value);
}

void				set_byte(t_arena *arena, unsigned char byte, int num)
{
	if (num > 4095)
		num %= 4096;
	arena->map[num] = byte;
}

int					set_mem(t_arena *arena, unsigned char *mem, int num, int size)
{
	int				set_value;
	int				i;

	i = 0;
	set_value = 0;
	while (mem && i < size)
	{
		set_byte(arena, mem[i], num++);
		set_value += mem[i++];
	}
	return (set_value);
}

void		set_reg(t_arena *arena, int reg, int adress)
{
	int		size;
	int		shift;

	size = REG_SIZE;
	shift = 0;
	while (size--)
	{
		set_byte(arena, (reg >> shift) & 255, adress++);
		shift += 8;
	}
}
