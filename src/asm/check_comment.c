/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:52:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		check_comment(char *line, t_file *ssl)
{
	int		j;
	char	*s;

	j = 0;
	s = ft_strnew(COMMENT_LENGTH);
	ssl->a += 8;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		(ssl->a)++;
	if (line[ssl->a] != '"')
		check_comment2(line, ssl);
	(ssl->a)++;
	while (line[ssl->a] && line[ssl->a] != '"')
		s[j++] = line[(ssl->a)++];
	if (line[ssl->a] != '"')
		j = check_comment3(line, ssl, j, s);
	if (j > COMMENT_LENGTH)
		write_error("VERY LONG COMMENT");
	ft_bzero(ssl->comment, COMMENT_LENGTH);
	ft_strncpy(ssl->comment, s, j);
	ssl->c = 1;
	ft_memdel((void **)&s);
}
