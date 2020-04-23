/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:13:47 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void				line_to_write(t_exec **com, t_file *ssl)
{
	t_exec			*current;
	unsigned char	*s;
	int				i;

	if (!*com)
		write_error("ERROR NOTHING TO DO");
	current = *com;
	while (current)
	{
		if (!(s = (unsigned char*)malloc(sizeof(unsigned char)
				* (current->n_bytes))))
			return ;
		s[0] = current->inst;
		i = 1;
		if (current->ta)
			s[i++] = current->ta;
		i = line_part(current, s, i, 1);
		if (current->ta2 != 0)
			i = line_part(current, s, i, 2);
		if (current->ta3 != 0)
			i = line_part(current, s, i, 3);
		line_to_write2(current->n_bytes, ssl, i, s);
		current = current->next;
		ft_memdel((void**)&s);
	}
}
