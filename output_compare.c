/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 11:49:45 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/02 11:09:33 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/libft.h"

int			main(int argc, char **argv)
{
	char	*line1;
	char	*line2;
	int		fd1;
	int		fd2;
	int		flag;
	int		line_counter;

	line_counter = 1;
	flag = 0;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		ft_printf("не вышло, поробуй еще раз...");
	while (get_next_line(fd1, &line1) > 0 && get_next_line(fd2, &line2) > 0)
	{
		if (ft_strcmp(line1, line2) != 0)
		{
			flag = 1;
			break ;
		}
		line_counter++;
		free(line1);
		free(line2);
	}
	if (flag)
		printf("\n\n%s %d\n\norigin: %s\nmy_out: %s\n\n", "Fail on line", line_counter, line1, line2);
	else
		ft_printf("различий не найдено\n");
	return (0);
}

//gcc -g output_compare.c libft/libft.a -o compare
