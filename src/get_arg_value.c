/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:11:07 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/18 09:32:41 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
Функция определяет сколько байт должна пройти каретка, чтобы оказаться на нужном аргументе
*/

int			count_skiplen(t_card *card, int desire_arg)
{
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (++i < desire_arg)
	{
		if (card->args[i] == REG_CODE)
			len += 1;
		else if (card->args[i] == IND_CODE)
			len += IND_SIZE;
		else if (card->args[i] == DIR_CODE)
			len += card->op->t_dir_size;
	}
	return (len);
}

/*
Функция возращает числовое значение аргумента в зависимости от его типа. Каретка во время исполнения не двигается
При аргументе T_REG возращается значение храняещееся регистре
*/

int			get_arg_value(t_arena *arena, t_card *card, int num, bool mod)
{
	int		dir_size;
	int		value;
	int		size;
	int		adress;

	dir_size = card->op->t_dir_size;
	adress = card->cursor + card->steps;
	if (card->args[num] == REG_CODE)
	{
		card->steps += 1;
		value = get_char(arena, adress) - 1;
		return (card->regs[value]);
	}
	if (card->args[num] == IND_CODE)
	{
		card->steps += IND_SIZE;
		value = get_twobytes(arena, adress);
		adress = cursor_to(card->cursor + value);
		adress = (mod) ? adress % IDX_MOD : adress;
	}
	else
		card->steps += dir_size;
	size = (card->args[num] == DIR_CODE) ? dir_size : 4;
	if (size == 4)
		value = get_fourbytes(arena, adress);
	else
		value = get_twobytes(arena, adress);
	return (value);
}

/*
Функция вычисляет ячейку в которой хранится номер регистра и возращает его в числовом представлении
*/

int			get_nreg(t_arena *arena, t_card *card, int num)
{
	int		dir_size;
	int		nreg;
	int		pos;

	dir_size = card->op->t_dir_size;
	pos = card->cursor + card->steps;
	nreg = get_char(arena, pos) - 1;
	card->steps += 1;
	return (nreg);
}
