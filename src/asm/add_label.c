/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:36:22 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	add_label(t_label **list, t_label *new)
{
	t_label	*current;

	if (list || new)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
			{
				current = current->next;
			}
			current->next = new;
		}
		else
			*list = new;
	}
}
