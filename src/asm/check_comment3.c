/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:05:41 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		check_comment3(char *line, t_file *ssl, int j, char *s)
{
	s[j++] = '\n';
	while ((get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		while (line[ssl->a] && line[ssl->a] != '"')
			s[j++] = line[(ssl->a)++];
		if (line[ssl->a] == '"')
			break ;
		s[j++] = '\n';
		ft_strdel(&line);
	}
	if (line[ssl->a] != '"')
		write_error("ERROR NO FINISH COMMENT");
	return (j);
}
