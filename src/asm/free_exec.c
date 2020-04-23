/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 08:42:01 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		free_exec(t_exec *com)
{
	t_exec	*t;

	while (com)
	{
		t = com;
		com = com->next;
		ft_memdel((void**)&(t->a1));
		ft_memdel((void**)&(t->a2));
		ft_memdel((void**)&(t->a3));
		ft_memdel((void **)&t);
	}
	ft_memdel((void**)&com);
}
