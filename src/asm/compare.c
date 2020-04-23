/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:00:01 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	compare(t_file *ssl, char *line, int j, t_exec *com)
{
	if (ft_strncmp(&line[ssl->a - j], "live", j) == 0)
		live(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "ld", j) == 0)
		ld(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "st", j) == 0)
		st(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "add", j) == 0)
		add(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "sub", j) == 0)
		sub(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "and", j) == 0)
		and(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "or", j) == 0)
		ft_or(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "xor", j) == 0)
		ft_xor(ssl, line, com);
	else if (ft_strncmp(&line[ssl->a - j], "zjmp", j) == 0)
		zjmp(ssl, line, com);
	else
		compare_2(ssl, line, j, com);
}
