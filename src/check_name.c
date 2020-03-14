/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:25:29 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/13 08:03:35 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	check_name(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[PROG_NAME_LENGTH + 1];
	size_t 			i;

	if ((text = read(fd, &buffer, PROG_NAME_LENGTH)) == -1)
		write_error("ERROR WITH THE READING A FILE");
	if (text < PROG_NAME_LENGTH)
		write_error("INVALID SIZE");
	i = 0;
	while (buffer[i] != '\0')
		i++;
	if (!(player->name = (char *)malloc(sizeof(char) * (i + 1))))
		exit(0);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (i < PROG_NAME_LENGTH)
		{
			player->name[i] = 0;
			player->name[i] |= buffer[i];
		}
		else
			write_error("INVALID SIZE");
		i++;
	}
	player->name[i] = '\0';
}
