/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg3_dv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 17:53:28 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	take_arg3_dv(char *line, t_file *ssl, t_exec *com, int i)
{
	while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
		i++;
	if ((i > 1) && is_limit(line[ssl->a + i]))
	{
		if (!(com->a3 = ft_strsub(line, ssl->a + 1, i - 1)))
			write_error("ERROR_ARGUMENT_INIT");
	}
	else
		write_error("WRONG_LABEL_NAME");
	com->ta3 = 5;
	ssl->a = ssl->a + i;
}
