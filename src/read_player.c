/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:49:39 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/13 09:14:38 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void			check_flag_n(char *argv, t_general *all)
{
	if (is_numvalue(argv))
	{
		all->flag_n = ft_atoi(argv);
		if (all->flag_n < 0)
			write_error("THE NUMBER COULDN'T BE NEGATIVE");
	}
	else
		write_error("INVALID NUMBER");
}

static void			check_flag_dump(char *argv, t_general *all)
{
	if (is_numvalue(argv))
	{
		all->stop_cycle = ft_atoi(argv);
		if (all->stop_cycle < 0)
			write_error("THE NUMBER COULDN'T BE NEGATIVE");
	}
	else
		write_error("INVALID NUMBER");
}

void	read_player(char **argv, t_general *all) //проверка расширения файлы и оправка на валидацию
{
	int fd;
	int	n_player;
	int i;
	int j;

	i = 1;
	n_player = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
			j++;
		if (ft_strcmp("-dump", argv[i]) == 0)
		{
			i++;
			check_flag_dump(argv[i], all);
		}
		else if (ft_strcmp("-n", argv[i]) == 0)
		{
			i++;
			check_flag_n(argv[i++], all);
		}
		else if (argv[i][j - 4] == '.' && argv[i][j - 3] == 'c' &&
			argv[i][j - 2] == 'o' && argv[i][j - 1] == 'r')
		{
			if (n_player > 4)
				write_error("TOO MANY PLAYERS");
			fd = open(argv[i], O_RDONLY);
			valid_check(fd, argv[i], n_player++, all);
		}
		else
			write_error("INVALID FILE");
		i++;
	}
}