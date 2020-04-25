/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:49:39 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/25 09:05:22 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		sort_players(t_player **players, int size)
{
	t_player	*tmp;
	int			i;
	int			j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (players[j]->num > players[j + 1]->num)
			{
				tmp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

static void		get_avails_num(int *avail, t_general *all)
{
	int			j;
	int			z;
	int			k;

	k = 0;
	z = 1;
	while (z <= all->n_players)
	{
		j = 0;
		while (j < all->n_players && all->reserved_nums[j] != z)
		{
			if (all->reserved_nums[j] > all->n_players)
				print_help();
			j++;
		}
		if (j == all->n_players)
			avail[k++] = z;
		z++;
	}
}

static void		assign_numbers(t_general *all)
{
	int			avail_nums[4];
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_bzero(avail_nums, sizeof(int) * 4);
	get_avails_num(avail_nums, all);
	while (i < all->n_players)
	{
		if (!all->players[i]->num)
			all->players[i]->num = avail_nums[j++];
		i++;
	}
	sort_players(all->players, all->n_players);
}

static bool		is_cor_file(char *argv)
{
	int			j;

	j = ft_strlen(argv);
	return (argv[j - 4] == '.'
			&& argv[j - 3] == 'c'
			&& argv[j - 2] == 'o'
			&& argv[j - 1] == 'r');
}

void			read_player(int argc, char **argv, t_general *all)
{
	int fd;
	int i;

	i = 1;
	while (i < argc)
	{
		if (is_flags(i, argc, argv, all))
			i += 2;
		else if (is_cor_file(argv[i]))
		{
			fd = open(argv[i], O_RDONLY);
			valid_check(fd, (all->n_players)++, all);
			close(fd);
			if (all->n_players > 4)
				write_error("Too many champions\n");
			i++;
		}
		else
			print_help();
	}
	if (all->n_players < 1)
		print_help();
	assign_numbers(all);
}
