/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 12:46:12 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	no_separator(t_file *ssl, char *line)
{
	while (line[ssl->a] && line[ssl->a] != ',')
	{
		if (line[ssl->a] == '\n')
			write_error("END_OF_LINE DURING_TAKING_ARGUMENT");
		if (!is_whitespace(line[ssl->a]))
			write_error("__SEPARATOR_ERROR__");
		ssl->a = ssl->a + 1;
	}
	ssl->a = ssl->a + 1;
}
