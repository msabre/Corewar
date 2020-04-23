/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:26:19 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	st(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	if ((com->ta1) != 1)
		write_error("ERROR_TYPE_ARGUMENT_ST_COMMAND");
	no_separator(ssl, line);
	take_arg2(line, ssl, com);
	com->inst = 3;
	com->n_bytes = 5;
	com->dir_size = 4;
	if (com->ta2 == 2 || com->ta2 == 3)
		write_error("ERROR_TYPE_ARGUMENT_ST_COMMAND");
	if (com->ta2 == 1)
		com->n_bytes = 4;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl->a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_TWO_ARGUMENT_TO_ST");
}
