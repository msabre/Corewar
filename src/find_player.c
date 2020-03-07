/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:34:19 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/07 14:12:20 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_player		*get_player(t_player *players, int num)
{
	while (players)
	{
		if (players->num == num)
			break ;
		players = players->next;
	}
	return (players);
}