/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:05:12 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/11 10:49:47 by andrejskobe      ###   ########.fr       */
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

int		cursor_steps(int current_position, int count)
{
	int	steps;

	steps = current_position + count;
	if (steps > 4095)
		steps %= 4095;
	return (steps);
}
