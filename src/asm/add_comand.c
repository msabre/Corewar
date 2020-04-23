/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_comand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 10:50:11 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	add_comand(t_exec *list, t_exec *new)
{
	t_exec	*current;

	if (list || new)
	{
		if (list)
		{
			current = list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			list = new;
	}
}
