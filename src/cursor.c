/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:05:12 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/10 14:14:23 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		cursor_next(int current_position)
{
	if (current_position > 4095)
		current_position %= 4095 + 1;
	return (current_position);
}

int		cursor_to(int go_to)
{
	if (go_to > 4095)
		go_to %= 4095;
	return (go_to);
}
