/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:11:07 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/12 14:13:38 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
Функция определяет сколько байт должна пройти каретка, чтобы оказаться на нужном аргументе
*/

int			count_skiplen(char *args, int desire_arg, int t_dir_size)
{
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (++i < desire_arg)
	{
		if (args[i] == T_REG)
			len += 1;
		else if (args[i] == T_IND)
			len += IND_SIZE;
		else if (args[i] == T_DIR)
			len += t_dir_size;
	}
	return (len);
}

/*
Функция возращает числовое значение аргумента в зависимости от его типа. Каретка во время исполнения не двигается
При аргументе T_REG возращается значение храняещееся регистре
*/

int			get_arg_value(t_general *all, char *args, int num, bool mod)
{
	int		t_dir_size;
	int		value;
	int		size;
	int		pos;

	t_dir_size = all->cards->op->t_dir_size;
	pos = all->cards->cursor + count_skiplen(args, num, t_dir_size);
	if (args[num] == T_REG)
	{
		value = get_char(&all->arena, pos) - 1;
		return (all->cards->regs[value]);
	}
	if (args[num] == T_IND)
	{
		pos += get_bytes(&all->arena, pos, 2);
		pos = (mod) ? pos % IDX_MOD : pos;
	}
	size = (args[num] == T_DIR) ? t_dir_size : 4;
	value = get_bytes(&all->arena, pos, size);
	return (value);
}

/*
Функция вычисляет ячейку в которой хранится номер регистра и возращает его в числовом представлении
*/

int			get_nreg(t_arena *arena, char *args, int num, int t_dir_size)
{
	int		nreg;
	int		pos;

	pos = count_skiplen(args, num, t_dir_size);
	nreg = get_char(arena, pos) - 1;
	return (nreg);
}
