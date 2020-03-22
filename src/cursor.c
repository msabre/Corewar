/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:05:12 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/20 10:00:02 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		cursor_next(int current_position)
{
	current_position %= MEM_SIZE;
	if (current_position < 0)
		current_position += MEM_SIZE;
	current_position += 1;
	return (current_position);
}

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
