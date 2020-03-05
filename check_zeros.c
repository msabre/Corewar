/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:40:02 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 17:17:51 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	check_zeros(int fd)
{
	int 			text;
	int32_t 		zero;
	unsigned char	buffer[T_IND + 1];
	size_t 			i;

	if ((text = read(fd, &buffer, T_IND)) == -1)
		write_error();
	if (text < T_IND)
		write_error();
	zero = 0x0;
	while (i < T_IND)
	{
		zero <<= 8;
		zero |= buffer[i];
		i++;
	}
	if (zero != ZEROS)
		write_error();
}