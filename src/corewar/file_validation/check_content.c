/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:50:22 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:09:46 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void				champ_comment(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[COMMENT_LENGTH];
	int				i;

	text = read(fd, &buffer, COMMENT_LENGTH);
	if (text == -1)
		write_error(READ_ERROR);
	if (text < COMMENT_LENGTH)
		write_error(SMALL_SIZE_CODE);
	if (!(player->comment = (char *)ft_memalloc(sizeof(char) * (text + 1))))
		exit(0);
	i = 0;
	while (i < text)
	{
		player->comment[i] |= buffer[i];
		i++;
	}
}

void				check_zeros(int fd)
{
	int				text;
	unsigned int	zero;
	unsigned char	buffer[T_IND + 1];
	int				i;

	i = 0;
	text = read(fd, &buffer, T_IND);
	if (text == -1)
		write_error(READ_ERROR);
	if (text < T_IND)
		write_error(CODE_SIZE_ERROR);
	zero = 0;
	while (i < T_IND)
	{
		zero <<= 8;
		zero |= buffer[i];
		i++;
	}
	if (zero != ZEROS)
		write_error(CODE_SIZE_ERROR);
}

void				check_champ_code(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[player->len_exec + 1];
	int				i;

	text = read(fd, &buffer, player->len_exec);
	if (text == -1)
		write_error(READ_ERROR);
	if (text < player->len_exec || read(fd, &buffer[0], player->len_exec) != 0)
		write_error(CODE_SIZE_ERROR);
	player->exe_code = (unsigned char *)
		ft_memalloc(sizeof(unsigned char *) * player->len_exec);
	if (!player->exe_code)
		exit(0);
	i = 0;
	while (i < player->len_exec)
	{
		player->exe_code[i] |= buffer[i];
		i++;
	}
}

void				check_magic(int fd)
{
	int				text;
	unsigned int	magic;
	unsigned char	buffer[T_IND + 1];
	int				i;

	i = 0;
	magic = 0;
	text = read(fd, &buffer, T_IND);
	if (text == -1)
		write_error(READ_ERROR);
	if (text < T_IND)
		write_error(HEADER_ERROR);
	while (i < T_IND)
	{
		magic <<= 8;
		magic |= buffer[i];
		i++;
	}
	if (magic != COREWAR_EXEC_MAGIC)
		write_error(HEADER_ERROR);
}

void				check_name(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[PROG_NAME_LENGTH + 1];
	int				i;

	text = read(fd, &buffer, PROG_NAME_LENGTH);
	if (text == -1)
		write_error(READ_ERROR);
	if (text < PROG_NAME_LENGTH)
		write_error(CODE_SIZE_ERROR);
	player->name = (unsigned char *)
		ft_memalloc(sizeof(unsigned char) * (text + 1));
	if (!player->name)
		exit(0);
	i = 0;
	while (buffer[i] != '\0')
	{
		player->name[i] |= buffer[i];
		i++;
	}
	player->name[i] = '\0';
}
