/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 11:49:45 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/23 13:02:05 by andrejskobe      ###   ########.fr       */
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
	fd1 = open("orig_out", O_RDONLY);
	fd2 = open("my_out", O_RDONLY);
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
	{
		ft_printf("\n\n%s %d\n\norigin: %s\nmy_out: %s\n\n", "Fail on line", line_counter, line1, line2);
	}
	return (0);
}

//gcc -g output_compare.c libft/libft.a -o compare
