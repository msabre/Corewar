/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:16:57 by msabre            #+#    #+#             */
/*   Updated: 2020/03/22 12:38:33 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int					next(t_arena *arena)
{
	arena->ind %= 4096;
	if (arena->ind < 0)
		arena->ind += MEM_SIZE;
	return (arena->map[arena->ind]);
}

unsigned char		get_char(t_arena *arena, int num)
{
	num %= MEM_SIZE;
	if (num < 0)
		num += MEM_SIZE;
	return (arena->map[num]);
}

int					get_twobytes(t_arena *arena, int start)
{
	short			value;
	int				i;

	i = 0;
	value = 0;
	while (i < 2)
	{
		value <<= 8 * i;
		value |= (int)get_char(arena, start++);
		i++;
	}
	return (value);
}

int					get_fourbytes(t_arena *arena, int start)
{
	int				value;
	int				i;

	i = 0;
	value = 0;
	while (i < 4)
	{
		value <<= 8;
		value |= (int)get_char(arena, start++);
		i++;
	}
	return (value);
}

void				set_byte(t_arena *arena, unsigned char byte, int num)
{
	num %= MEM_SIZE;
	if (num < 0)
		num += MEM_SIZE;
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
	unsigned char value;
	int		size;
	int		shift;

	size = REG_SIZE;
	shift = 0;
	while (size > 0)
	{
		value = (unsigned char)((reg >> shift) & 255);
		set_byte(arena, value, (adress + size - 1));
		shift += 8;
		size--;
	}
}
