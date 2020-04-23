/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 10:14:10 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:12:03 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static bool		hasnext(int i, int argc)
{
	if (i + 1 < argc)
		return (true);
	return (false);
}

static int		check_flag(char *n, char *argv_flag, t_general *all)
{
	static int	pos;
	int			flag;

	if (!is_numvalue(n))
		print_help();
	flag = ft_atoi(n);
	if (ft_strcmp("-n", argv_flag) == 0)
	{
		if (flag < 1 || flag > 4)
			print_help();
		all->pl_num = flag;
		all->reserved_nums[pos++] = flag;
	}
	else if (ft_strcmp("-dump", argv_flag) == 0
		|| ft_strcmp("-dump32", argv_flag) == 0)
	{
		all->stop_cycle = flag;
		if (ft_strcmp("-dump32", argv_flag) == 0)
			all->cn_octets = 32;
	}
	else if (ft_strcmp("-v", argv_flag) == 0)
		all->flag_v = flag;
	else if (ft_strcmp("-s", argv_flag) == 0)
		all->show_key = flag;
	return (1);
}

int				is_flags(int i, int argc, char **argv, t_general *all)
{
	if (ft_strcmp("-a", argv[i]) == 0)
		return (all->aff_key = 1);
	else if (ft_strcmp("-n", argv[i]) == 0 || ft_strcmp("-s", argv[i]) == 0
		|| ft_strcmp("-dump", argv[i]) == 0
		|| ft_strcmp("-dump32", argv[i]) == 0
		|| ft_strcmp("-v", argv[i]) == 0)
	{
		if (!hasnext(i, argc))
			print_help();
		return (check_flag(argv[i + 1], argv[i], all));
	}
	return (0);
}
