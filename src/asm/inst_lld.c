/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:11:06 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	lld(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	if (com->ta1 == 1)
		write_error("ERROR_TYPE_ARGUMENT_LLD_COMMAND");
	no_separator(ssl, line);
	take_arg2(line, ssl, com);
	com->inst = 13;
	com->n_bytes = 7;
	com->dir_size = 4;
	if (com->ta2 != 1)
		write_error("ERROR_TYPE_ARGUMENT_LLD_COMMAND");
	if (com->ta1 == 4 || com->ta1 == 5)
		com->n_bytes = 5;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl->a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_TWO_ARGUMENT_TO_LLD");
}
