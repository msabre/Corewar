/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cham_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:44:21 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 16:28:10 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	champ_comment(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[COMMENT_LENGTH + 1];
	size_t			i;

	if ((text = read(fd, &buffer, COMMENT_LENGTH)) == -1)
		write_error();
	if (text < COMMENT_LENGTH)
		write_error();
	i = 0;
	while (buffer[i] != '\0')
		i++;
	if (!(player->comment = (char *)malloc(sizeof(char) * i)))
		exit(0);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (i < COMMENT_LENGTH)
		{
			player->comment[i] <<= 8;
			player->comment[i] |= buffer[i];
		}
		else
			write_error();
		i++;
	}
}