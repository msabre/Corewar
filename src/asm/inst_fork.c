/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:09:06 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	ft_fork(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	if (com->ta1 < 2 || com->ta1 > 3)
		write_error("ERROR_ARGUMENT_FORK_COMMAND");
	com->n_bytes = 3;
	com->inst = 12;
	com->dir_size = 2;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl->a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_ONE_ARGUMENT_TO_FORK");
}
