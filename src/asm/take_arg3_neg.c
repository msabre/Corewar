/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg3_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 17:10:21 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	take_arg3_neg(char *line, t_file *ssl, t_exec *com, int i)
{
	while (ft_isdigit(line[ssl->a + i]))
		i++;
	if ((i > 1) && is_limit(line[ssl->a + i]))
	{
		if (!(com->a3 = ft_strsub(line, ssl->a, i)))
			write_error("ERROR_ARGUMENT_INIT");
	}
	else
		write_error("WRONG_NUMBER_ARGUMENT");
	com->ta3 = 4;
	ssl->a = ssl->a + i;
}
