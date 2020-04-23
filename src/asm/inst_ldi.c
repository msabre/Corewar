/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:00:02 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	ldi(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	no_separator(ssl, line);
	take_arg2(line, ssl, com);
	no_separator(ssl, line);
	take_arg3(line, ssl, com);
	if (com->ta3 != 1)
		write_error("ERROR_TYPE_ARGUMENT_LDI_COMMAND");
	if (com->ta2 == 4 || com->ta2 == 5)
		write_error("ERROR_TYPE_ARGUMENT_LDI_COMMAND");
	com->inst = 10;
	com->n_bytes = 7;
	com->dir_size = 2;
	if (com->ta1 == 1)
		com->n_bytes = com->n_bytes - 1;
	if (com->ta2 == 1)
		com->n_bytes = com->n_bytes - 1;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl->a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_THREE_ARGUMENT_TO_LDI");
}
