/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:15:58 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:23:31 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void	print_help(void)
{
	ft_printf("Usage: ./corewar [-dump N -s N -v N -n N]"
												"[-a] <champion1.cor> <...>\n");
	ft_printf("-a      : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE #########################################"
														"#################\n");
	ft_printf("-dump N   : Dumps 64 octets memory after N cycles then exits\n");
	ft_printf("-dump32 N : Dumps 32 octets memory after N cycles then exits\n");
	ft_printf("-n N    : assign a sequential number N to the player\n");
	ft_printf("-s N    : Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf("-v N    : Verbosity levels, can be added together"
												"to enable several\n");
	ft_printf("              - 0 : Show only essentials\n");
	ft_printf("              - 1 : Show lives\n");
	ft_printf("              - 2 : Show cycles\n");
	ft_printf("              - 4 : Show operations"
									"(Params are NOT litteral ...)\n");
	ft_printf("              - 8 : Show deaths\n");
	ft_printf("              - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("#####################################################"
										"###########################\n");
	exit(0);
}

void	write_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}
