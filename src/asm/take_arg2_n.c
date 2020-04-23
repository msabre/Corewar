/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg2_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:47:45 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	take_arg2_n(char *line, t_file *ssl, t_exec *com, int i)
{
	while (ft_isdigit(line[ssl->a + i]))
		i++;
	if (is_limit(line[ssl->a + i]))
	{
		if (!(com->a2 = ft_strsub(line, ssl->a, i)))
			write_error("ERROR_ARGUMENT_INIT");
	}
	else
		write_error("WRONG_NUMBER_ARGUMENT");
	com->ta2 = 4;
	ssl->a = ssl->a + i;
}
