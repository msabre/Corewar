/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg3_pr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 17:02:57 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	take_arg3_pr(char *line, t_file *ssl, t_exec *com, int i)
{
	if (line[ssl->a + i] == '-')
		take_arg3_pr_neg(line, ssl, com, 2);
	else if (ft_isdigit(line[ssl->a + i]) && ++i)
	{
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if ((i > 1) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a3 = ft_strsub(line, ssl->a + 1, i - 1)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
		com->ta3 = 2;
		ssl->a = ssl->a + i;
	}
	else
		write_error("WRONG_NUMBER_ARGUMENT");
}
