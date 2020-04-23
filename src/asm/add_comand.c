/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_comand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 10:50:11 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

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
