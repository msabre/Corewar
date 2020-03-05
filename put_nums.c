/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:15:28 by msabre            #+#    #+#             */
/*   Updated: 2020/03/05 16:00:00 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

static void			change_players(t_player *players, int n_pos, int n_val)
{
	t_player		*tmp;
	int             i;

	i = 0;
	tmp = players;
	while (i < n_pos - 1)
	{
		players = players->next;
		i++;
	}
	i = 0;
	while (i < n_val - 1)
	{
		tmp = tmp->next;
		i++;
	}
	players->next = tmp->next;
}

static int			gump_processing(t_flags *f, int i, int argc, char **argv)
{
	if (f->gump)
		return (-1);
	f->gump = 1;
	i++;
	if (argv[i] || !is_numvalue(argv[i]))
		return (-1);
	f->stop_cycle = ft_atoi(argv[i++]);
	return (i);
}

static int			n_processing(t_flags *f, int i, int argc, char **argv)
{
	if (f->n_value)
		return (-1);
	f->n_pos = i++;
	if (!argv[i] || !is_numvalue(argv[i]))
		return (-1);
	f->n_value = ft_atoi(argv[i++]);
	if (!f->n_value || i == argc || f->n_value >= argc)
		return (-1);
	return (i);
}

int					put_nums(t_general *all, int argc, char **argv)
{
	t_flags			f;
	int				curr_num;
	int				i;
	
	i = 1;
	f.n_value = 0;
	curr_num = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
		{
			i = n_processing(&f, i, argc, argv);
			if (i < 0)
				return (0);
		}
		else if (ft_strcmp(argv[i], "-gump") == 0)
		{
			i = gump_processing(&f, i, argc, argv);
			if (i < 0)
				return (0);
		}
		i++;
	}
	if (f.n_value)
		change_players(all->players, f.n_pos, f.n_value);
	if (f.gump)
		all->stop_cycle = f.stop_cycle;
	return (1);
}
