/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg2_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:28:32 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	take_arg2_d(char *line, t_file *ssl, t_exec *com, int i)
{
	while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
		i++;
	if ((i > 2) && is_limit(line[ssl->a + i]))
	{
		if (!(com->a2 = ft_strsub(line, ssl->a + 2, i - 2)))
			write_error("ERROR_ARGUMENT_INIT");
	}
	else
		write_error("WRONG_LABEL_ARGUMENT");
	com->ta2 = 3;
	ssl->a = ssl->a + i;
}
