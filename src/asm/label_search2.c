/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_search2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:32:39 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		label_search2(t_label **list, t_exec **com)
{
	t_label	*current;
	t_exec	*temp;

	temp = *com;
	if (*list)
	{
		current = *list;
		while (current)
		{
			if (ft_strequ(current->name, temp->a2))
			{
				if (temp->ta2 == 3)
					temp->ta2 = 2;
				else
					temp->ta2 = 4;
				ft_memdel((void**)&temp->a2);
				temp->a2 = ft_itoa(current->line_byte - temp->line_byte);
				return ;
			}
			current = current->next;
		}
	}
	write_error("NO_LABEL");
}
