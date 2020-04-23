/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:35 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		check_name(char *line, t_file *ssl)
{
	int		j;
	char	*s;

	j = 0;
	s = ft_strnew(PROG_NAME_LENGTH);
	ssl->a += 5;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		(ssl->a)++;
	if (line[ssl->a] != '"')
		check_name2(line, ssl);
	(ssl->a)++;
	while (line[ssl->a] && line[ssl->a] != '"')
		s[j++] = line[(ssl->a)++];
	if (line[ssl->a] != '"')
		j = check_name3(line, ssl, j, s);
	if (j > PROG_NAME_LENGTH)
		write_error("VERY LONG NAME");
	ft_bzero(ssl->name, PROG_NAME_LENGTH);
	ft_strncpy(ssl->name, s, j);
	ssl->n = 1;
	ft_memdel((void **)&s);
}
