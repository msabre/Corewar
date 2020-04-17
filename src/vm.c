/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:25:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/08 17:32:02 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			del_content(t_general *all)
{
	t_card		*ptr;
	int			i;

	i = 0;
	while (i < all->n_players)
	{
		free(all->players[i]->name);
		free(all->players[i]->comment);
		free(all->players[i]->exe_code);
		free(all->players[i]);
		i++;
	}
	while (all->cards)
	{
		ptr = all->cards;
		all->cards = all->cards->next;
		free(ptr);
	}
}

void			announce_players(t_player **players, int count)
{
	int			i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < count)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			players[i]->num, players[i]->len_exec,
				players[i]->name, players[i]->comment);
		i++;
	}
}

static void		print_arena(unsigned char *arena)
{
	int			j;
	int			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		ft_printf("0x%.4x : ", i);
		while (j < 32)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		write (1, "\n", 1);
		i += 32;
	}
}

void			battle(t_general *all)
{
	announce_players(all->players, all->n_players);
	while (all->cards)
	{
		if (all->stop_cycle > 0 && all->cycles == all->stop_cycle)
		{
			print_arena(all->arena);
			return ;
		}
		check_cards(all, all->cards);
		if (all->cycles == 4096)
		    all = all;
		if ((all->cycles - all->last_check) == all->ctd
			|| all->ctd <= 0)
			check(all);
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		all->last_live->num, all->last_live->name);
}

int				main(int argc, char **argv) {
    t_general all;

    all.n_players = 0;
    all.stop_cycle = 0;
    all.pl_num = 0;
    all.flag_v = 0;
    ft_bzero(all.reserved_nums, sizeof(int) * 4);
    if (argc == 1)
        print_help();
    read_player(argc, argv, &all);
	prepare_game(&all);
	battle(&all);
	del_content(&all);
	return (0);
}
