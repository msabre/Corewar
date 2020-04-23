/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:00 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

int		main(int argc, char **argv)
{
	char	*line;
	t_file	*ssl;

	ssl = init_ssl();
	if (argc > 1)
	{
		rename_f(argc, argv, &ssl);
		if ((ssl->fd = open(argv[argc - 1], O_RDONLY)) == -1)
			write_error("DOESNT READ FILE_CHECK NAME\n");
		line = NULL;
		skolkovo(line, ssl);
		close(ssl->fd);
		free_t_file(ssl);
		ft_strdel(&line);
	}
	else
		write_error("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
