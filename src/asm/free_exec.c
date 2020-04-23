/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 08:42:01 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

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
