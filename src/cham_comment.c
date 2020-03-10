/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cham_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:44:21 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/10 14:39:02 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	champ_comment(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[COMMENT_LENGTH + 1];
	size_t			i;

	if ((text = read(fd, &buffer, COMMENT_LENGTH)) == -1)
		write_error("ERROR WITH THE READING A FILE");
	if (text < COMMENT_LENGTH)
		write_error("INVALID SIZE");
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
			player->comment[i] = 0;
			player->comment[i] |= buffer[i];
		}
		else
			write_error("INVALID SIZE");
		i++;
	}
}
