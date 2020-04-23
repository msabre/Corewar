/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 19:16:48 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

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
