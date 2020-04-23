/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 12:46:12 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

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
