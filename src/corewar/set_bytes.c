/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:16:57 by msabre            #+#    #+#             */
/*   Updated: 2020/04/23 15:13:09 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void				set_byte(unsigned char *arena, unsigned char byte, int num)
{
	num %= MEM_SIZE;
	if (num < 0)
		num += MEM_SIZE;
	arena[num] = byte;
}

int					set_mem(unsigned char *arena,
					unsigned char *mem, int num, int size)
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

void				set_reg(unsigned char *arena, int reg, int adress)
{
	unsigned char	value;
	int				size;
	int				shift;

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
