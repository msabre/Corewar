/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:44:30 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_exec		*init_exec(void)
{
	t_exec *temp;

	temp = (t_exec *)malloc(sizeof(t_exec));
	temp->inst = 0;
	temp->dir_size = 0;
	temp->kta = NULL;
	temp->ta = 0;
	temp->line_byte = 0;
	temp->n_bytes = 0;
	temp->a1 = NULL;
	temp->ta1 = 0;
	temp->a2 = NULL;
	temp->ta2 = 0;
	temp->a3 = NULL;
	temp->ta3 = 0;
	temp->next = NULL;
	return (temp);
}
