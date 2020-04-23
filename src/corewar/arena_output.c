/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:38:14 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 23:05:35 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void	print_arena(unsigned char *arena, int octets)
{
	int		j;
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		ft_printf("0x%.4x : ", i);
		while (j < octets)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		write(1, "\n", 1);
		i += octets;
	}
}

void		arena_content_output(t_general *all)
{
	char	*empty;

	if (all->stop_cycle > 0 && all->cycles == all->stop_cycle)
	{
		print_arena(all->arena, all->cn_octets);
		exit(0);
	}
	if (all->show_key > 0 && all->cycles % all->show_key == 0)
	{
		print_arena(all->arena, all->cn_octets);
		write(1, "\n", 1);
		get_next_line(0, &empty);
		free(empty);
	}
}
