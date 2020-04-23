/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:26:01 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		rename_f(int argc, char **argv, t_file **sl)
{
	t_file	*ssl;
	int		j;

	ssl = *sl;
	j = 0;
	while (argv[argc - 1][j])
		j++;
	while (j != -1 && argv[argc - 1][j] != '.')
		j--;
	if (argv[argc - 1][j] == '.' && argv[argc - 1][j + 1] == 's')
	{
		if (!(ssl->f_name = (char*)malloc(sizeof(char *) * (j + 4))))
			exit(0);
		ssl->f_name[j++] = '.';
		ssl->f_name[j++] = 'c';
		ssl->f_name[j++] = 'o';
		ssl->f_name[j++] = 'r';
		ssl->f_name[j] = '\0';
		j = j - 5;
		while (j != -1)
		{
			ssl->f_name[j] = argv[argc - 1][j];
			j--;
		}
	}
}
