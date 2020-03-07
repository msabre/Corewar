/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:11:07 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/07 14:12:23 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
аргументы операций бывают разных типов, эта функция нужна чтобы определить тип аргумента и вернуть
его значение в числовом представлении. Во время исполнения передвигается каретка.
*/

int			get_arg_value(t_arena *arena, t_card *card, char arg, int t_dir_size) // arg - тип аргумента (10 || 11 || 01)
{
	int		arg_value;
	int		n_reg;
	int		size;
	int		i;

	arg_value = 0;
	if (arg == t_dir_size)
		size = t_dir_size;
	else if (arg == T_IND)
		size = IND_SIZE;
	else if (arg == T_REG)
	{
		i = 0;
		n_reg = arena->map[card->curr_pos];
		while (i < 4)
			arg_value += card->regs[n_reg][i++];
		card->curr_pos += 1;
		return (arg_value);
	}
	while (size)
	{
		arg_value += arena->map[(card)->curr_pos++];
		size--;
	}
	return (arg_value);
}
