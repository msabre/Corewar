/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:59:51 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:13:00 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

unsigned char		get_char(unsigned char *arena, int num)
{
	num %= MEM_SIZE;
	if (num < 0)
		num += MEM_SIZE;
	return (arena[num]);
}

int					get_twobytes(unsigned char *arena, int start)
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

int					get_fourbytes(unsigned char *arena, int start)
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
