/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:05:12 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:15:59 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		cursor_move(t_card *card)
{
	int	adress;

	adress = card->cursor + card->steps;
	adress %= MEM_SIZE;
	if (adress < 0)
		adress += MEM_SIZE;
	return (adress);
}

int		cursor_to(int go_to)
{
	go_to %= MEM_SIZE;
	if (go_to < 0)
		go_to += MEM_SIZE;
	return (go_to);
}

int		cursor_steps(int current_position, int count)
{
	int	steps;

	steps = current_position + count;
	steps %= MEM_SIZE;
	if (steps < 0)
		steps += MEM_SIZE;
	return (steps);
}
