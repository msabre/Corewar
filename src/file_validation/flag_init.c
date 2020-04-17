/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 10:14:10 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/08 17:08:21 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static bool		hasnext(int i, int argc)
{
	if (i + 1 < argc)
		return (true);
	return (false);
}

static int		check_flag_v(char *argv, t_general *all)
{
	if (is_numvalue(argv))
	{
		all->flag_v = ft_atoi(argv);
		return (1);
	}
	else
		print_help();
	return (0);
}

static int		check_flag_n(char *argv, t_general *all)
{
	static int	pos;
	int			num_order;

	if (is_numvalue(argv))
	{
		num_order = ft_atoi(argv);
		if (num_order < 1 || num_order > 4)
			print_help();
		all->pl_num = num_order;
		all->reserved_nums[pos++] = num_order;
		return (1);
	}
	else
		print_help();
	return (0);
}

static int		check_flag_dump(char *argv, t_general *all)
{
	if (is_numvalue(argv))
	{
		all->stop_cycle = ft_atoi(argv);
		if (all->stop_cycle < 0)
			print_help();
		return (1);
	}
	else
		print_help();
	return (0);
}

int				is_flags(int i, int argc, char **argv, t_general *all)
{
	if (ft_strcmp("-v", argv[i]) == 0)
	{
		if (!hasnext(i, argc))
			print_help();
		return (check_flag_v(argv[++i], all));
	}
	else if (ft_strcmp("-a", argv[i]) == 0)
		return (all->aff_key = 1);
	else if (ft_strcmp("-dump", argv[i]) == 0)
	{
		if (!hasnext(i, argc))
			print_help();
		return (check_flag_dump(argv[++i], all));
	}
	else if (ft_strcmp("-n", argv[i]) == 0)
	{
		if (!hasnext(i, argc))
			print_help();
		return (check_flag_n(argv[++i], all));
	}
	return (0);
}
