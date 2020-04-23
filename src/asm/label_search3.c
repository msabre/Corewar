/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_search3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:48:47 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		label_search3(t_label **list, t_exec **com)
{
	t_label	*current;
	t_exec	*temp;

	temp = *com;
	if (*list)
	{
		current = *list;
		while (current)
		{
			if (ft_strequ(current->name, temp->a3))
			{
				if (temp->ta3 == 3)
					temp->ta3 = 2;
				else
					temp->ta3 = 4;
				ft_memdel((void**)&temp->a3);
				temp->a3 = ft_itoa(current->line_byte - temp->line_byte);
				return ;
			}
			current = current->next;
		}
	}
	write_error("NO_LABEL");
}
