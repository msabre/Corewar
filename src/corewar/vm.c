/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:25:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/25 08:55:43 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

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

void			battle(t_general *all)
{
	announce_players(all->players, all->n_players);
	while (all->cards)
	{
		if (all->stop_cycle > 0 || all->show_key > 0)
			arena_content_output(all);
		check_cards(all, all->cards);
		if ((all->cycles - all->last_check) == all->ctd
			|| all->ctd <= 0)
			check(all);
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		all->last_live->num, all->last_live->name);
}

static void		standart_initial(t_general *all)
{
	all->arg_types[0] = T_REG;
	all->arg_types[1] = T_DIR;
	all->arg_types[2] = T_IND;
	all->n_players = 0;
	all->stop_cycle = 0;
	all->pl_num = 0;
	all->flag_v = 0;
	all->show_key = 0;
	all->cn_octets = 64;
	ft_bzero(all->reserved_nums, sizeof(int) * 4);
}

int				main(int argc, char **argv)
{
	t_general all;

	if (argc == 1)
		print_help();
	standart_initial(&all);
	read_player(argc, argv, &all);
	prepare_game(&all);
	battle(&all);
	del_content(&all);
	return (0);
}
