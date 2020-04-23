/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   including_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:40:27 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void				including_magic(int text)
{
	int				i;
	unsigned char	buffer[4];

	i = 0;
	while (i < 4)
	{
		buffer[i] = COREWAR_EXEC_MAGIC >> (8 * (3 - i));
		i++;
	}
	write(text, buffer, 4);
}
