/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:41:52 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

t_label		*cnl(char *name, int byte_c)
{
	t_label	*temp;

	if (!(temp = (t_label *)ft_memalloc(sizeof(t_label))))
		write_error("ERROR_LABEL_INIT");
	temp->name = name;
	temp->line_byte = byte_c;
	temp->next = NULL;
	return (temp);
}
