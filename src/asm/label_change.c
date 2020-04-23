/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:17:29 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void		label_change(t_label *list, t_exec **com)
{
	t_exec	*current;

	if (*com && list)
	{
		current = *com;
		while (current)
		{
			if (current->ta1 == 3 || current->ta1 == 5)
				label_search1(&list, &current);
			if (current->ta2 == 3 || current->ta2 == 5)
				label_search2(&list, &current);
			if (current->ta3 == 3 || current->ta3 == 5)
				label_search3(&list, &current);
			current = current->next;
		}
	}
}
