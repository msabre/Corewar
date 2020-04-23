/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:23:51 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 22:13:58 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static t_player		*init_player(int num)
{
	t_player *ssl;

	if (!(ssl = (t_player *)ft_memalloc(sizeof(t_player))))
		exit(0);
	ssl->num = num;
	return (ssl);
}

static void			length_exec_code(int fd, t_player *player)
{
	int				text;
	unsigned char	buffer[T_IND + 1];
	size_t			i;

	i = 0;
	player->len_exec = 0;
	text = read(fd, &buffer, T_IND);
	if (text < 0)
		write_error(READ_ERROR);
	if (text < T_IND)
		write_error(CODE_SIZE_ERROR);
	while (i < T_IND)
	{
		player->len_exec <<= 8;
		player->len_exec |= buffer[i];
		i++;
	}
	if (player->len_exec > 682)
		write_error(BIG_SIZE_CODE);
}

void				valid_check(int fd, int order_num, t_general *all)
{
	t_player		*player;

	player = init_player(all->pl_num);
	check_magic(fd);
	check_name(fd, player);
	check_zeros(fd);
	length_exec_code(fd, player);
	champ_comment(fd, player);
	check_zeros(fd);
	check_champ_code(fd, player);
	all->players[order_num] = player;
	all->pl_num = 0;
}
