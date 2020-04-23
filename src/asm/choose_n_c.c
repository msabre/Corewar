/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_n_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:41:24 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	choose_n_c(char *line, t_file *ssl, char *n, char *c)
{
	while (line[ssl->a])
	{
		skip_probel(ssl, line);
		no_comment(ssl, line);
		ft_strncpy(n, &line[ssl->a], 5);
		ft_strncpy(c, &line[ssl->a], 8);
		if (line[ssl->a])
		{
			if (ft_strcmp(n, ".name") == 0 && !ssl->n)
			{
				check_name(line, ssl);
				break ;
			}
			else if (ft_strcmp(c, ".comment") == 0 && !ssl->c)
			{
				check_comment(line, ssl);
				break ;
			}
			else
				write_error("COMMENT AND NAME ERROR");
		}
	}
}
