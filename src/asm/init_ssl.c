/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ssl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 10:16:36 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

t_file		*init_ssl(void)
{
	t_file	*temp;

	temp = (t_file *)malloc(sizeof(t_file));
	*temp->name = 0;
	*temp->comment = 0;
	temp->a = 0;
	temp->zero[0] = 0;
	temp->zero[1] = 0;
	temp->zero[2] = 0;
	temp->zero[3] = 0;
	temp->fd = 0;
	temp->line_byte = 0;
	temp->text = 0;
	temp->n = 0;
	temp->c = 0;
	return (temp);
}
