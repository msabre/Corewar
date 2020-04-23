/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:24:32 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	compare_2(t_file *ssl, char *line, int j, t_exec *com)
{
	if (ft_strncmp(&line[ssl->a - j], "ldi", j) == 0)
		ldi(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "sti", j) == 0)
		sti(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "fork", j) == 0)
		ft_fork(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "lld", j) == 0)
		lld(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "lldi", j) == 0)
		lldi(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "lfork", j) == 0)
		lfork(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "aff", j) == 0)
		aff(ssl, line, com);
	else
		write_error("WRONG OPERATION");
}
