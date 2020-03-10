/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:11:07 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/10 12:56:23 by andrejskobe      ###   ########.fr       */
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
		if (args[i] == T_DIR)
			len += REG_SIZE;
		else if (args[i] == T_IND)
			len += IND_SIZE;
		else if (args[i] == T_DIR)
			len += t_dir_size;
	}
	return (len);
}

/*
Функция возращает числовое значение аргумента в зависимости от его типа. Каретка во время исполнения не двигается
*/

int			get_arg_value(t_general *all, char *args, int num, int t_dir_size) // arg - тип аргумента (10 || 11 || 01)
{
	char	*adress;
	int		value;
	int		pos;
	int		i;

	pos = all->cards->curr_pos + count_skiplen(args, num, t_dir_size);
	if (args[num] == T_IND) // Получаем адрес
	{
		i = 2;
		value = 0;
		while (i-- > 0)
			value += all->arena.map[pos++];
		adress = &all->arena.map[value];
	}
	else if (args[num] == T_REG) // Получаем номер регистра
		adress = all->cards->regs[all->arena.map[pos] - 1];
	i = 0;
	value = 0;
	while (i < 4)
		value += adress[i++];
	return (value);
}

/*
Функция предназначена записывать байты с определенного адреса карты в регистр
*/

int			put_to_reg(char *arena, char **reg, int adress)
{
	int		value;
	int		i;

	i = 0;
	value = 0;
	while (i < 4)
	{
		(*reg)[i++] = arena[adress++];
		value += arena[adress];
	}
	return (value);
}
