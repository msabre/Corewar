/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:29:56 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void		arg_add(t_exec **com)
{
	t_exec	*current;
	int		i;

	if (!*com)
		return ;
	current = *com;
	while (current)
	{
		i = current->inst;
		if ((8 < i && i < 13) || i == 14 || i == 15)
			current->dir_size = 2;
		else
			current->dir_size = 4;
		if (i != 1 && i != 9 && i != 12 && i != 15)
		{
			kod_type_arg(&current);
		}
		current = current->next;
	}
}
