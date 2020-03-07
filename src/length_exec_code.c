/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_exec_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:24:48 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 16:29:51 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	length_exec_code(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[T_IND + 1];
	size_t			i;

	if ((text = read(fd, &buffer, T_IND)) == -1)
		write_error("ERROR WITH THE READING A FILE");
	if (text < T_IND)
		write_error("INVALID SIZE");
	player->len_exec = 0x0;
	i = 0;
	while (i < T_IND)
	{
		player->len_exec <<= 8;
		player->len_exec |= buffer[i];
		i++;
	}
	player->len_exec = (int)player->len_exec;
}
