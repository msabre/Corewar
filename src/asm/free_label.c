/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 19:16:48 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	free_label(t_label *list)
{
	t_label	*t;

	while (list)
	{
		t = list;
		list = list->next;
		ft_memdel((void**)&(t->name));
		ft_memdel((void**)&t);
	}
}
