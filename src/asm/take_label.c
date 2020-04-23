/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 09:52:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		take_label(char *line, t_file *ssl, t_label **list, t_exec *co)
{
	int		i;
	t_exec	*com;

	com = NULL;
	i = 0;
	while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
		i++;
	if ((i) && line[ssl->a + i] == ':')
		take_label2(line, ssl, i, list);
	else if (i)
	{
		ssl->a = ssl->a + i;
		if (1 < i && i < 6)
			com = take_opera(ssl, line, i, com);
		else
			write_error("WRONG_OPERATOR");
		add_comand(co, com);
	}
	else
		write_error("WRONG_LABEL_STRING");
}
