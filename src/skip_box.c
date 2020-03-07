/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:05:16 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 17:11:49 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_player		*skip_box(t_player *player)
{
	t_player	*temp;

	temp = player;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}