/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:34:04 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/06 16:27:33 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	check_magic(int fd)
{
	int				text;
	unsigned int	magic;
	unsigned char	buffer[T_IND + 1];
	size_t 			i;

	if ((text = read(fd, &buffer, T_IND)) == -1)
		write_error("ERROR WITH THE READING A FILE");
	if (text < T_IND)
		write_error("INVALID SIZE");
	magic = 0x0;
	i = 0;
	while (i < T_IND)
	{
		magic <<= 8;
		magic |= buffer[i];
		i++;
	}
	if (magic != COREWAR_EXEC_MAGIC)
		write_error("INVALID SIZE");
}