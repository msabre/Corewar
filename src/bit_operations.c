/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:23:30 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/09 14:40:47 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static char	make_bit_op(char a, char b, char op)
{
	if (op == '&')
		return (a & b);
	else if (op == '|')
		return (a | b);
	else if (op == '^')
		return (a ^ b);
	else
		return (0);
}

static void	put_opres(char *dst, char *arg1, char *arg2, char op)
{

	int		i;

	i = 0;
	while (i < 4)
	{
		dst[i] = make_bit_op(arg1[i], arg2[i], op);
		i++;
	}
}

void		bit_op_reg(t_general *all, t_card *card, char *args, char op)  // 22 строки
{
	int		r;
	int		adress;
	char	*arg_1;
	char	*arg_2;

	arg_1 = card->regs[r];
	r = all->arena.map[(card)->curr_pos];
	if (args[1] == T_REG)
	{
		adress = all->arena.map[(card)->curr_pos];
		arg_2 = card->regs[adress];
		put_opres(card->regs[args[2]], arg_1, arg_2, op);
	}
	else
	{
		if (args[1] == T_DIR)
			adress = card->curr_pos;
		else
			adress = get_arg_value(all, args, 1, 4);
		arg_2 = &all->arena.map[adress];
		put_opres(card->regs[args[2]], arg_1, arg_2, op);
		card->curr_pos += (args[0] == T_DIR) ? DIR_SIZE : IND_SIZE;
	}
}

void		bit_op_dir(t_general *all, t_card *card, char *args, char op)  // 23 строки
{
	int		adress;
	char	*arg_1;
	char	*arg_2;

	arg_1 = &all->arena.map[card->curr_pos];
	if (args[1] == T_REG)
	{
		adress = all->arena.map[card->curr_pos + DIR_SIZE];
		arg_2 = card->regs[adress];
		put_opres(card->regs[args[2]], arg_1, arg_2, op);
		card->curr_pos += REG_SIZE;
	}
	else
	{
		if (args[1] == T_DIR)
			adress = card->curr_pos + DIR_SIZE;
		else
			adress = get_arg_value(all, args, 1, 4);
		arg_2 = &all->arena.map[adress];
		put_opres(card->regs[args[2]], arg_1, arg_2, op);
		card->curr_pos += (args[0] == T_DIR) ? DIR_SIZE : IND_SIZE; // Проверено
	}
}

void		bit_op_in(t_general *all, t_card *card, char *args, char op) // 23 строки
{
	char	*arg_1;
	char	*arg_2;
	int		adress;

	adress = get_arg_value(all, args, 0, 4);
	arg_1 = &all->arena.map[adress];
	if (args[1] == T_REG)
	{
		adress = all->arena.map[card->curr_pos + IND_SIZE];
		arg_2 = card->regs[adress];
		put_opres(card->regs[args[2]], arg_1, arg_2, op);
		card->curr_pos += IND_SIZE + REG_SIZE; // Проверено
	}
	else
	{
		if (args[1] == DIR_SIZE)
			adress += IND_SIZE;
		else
			adress += get_arg_value(all, args, 1, 4);
		arg_2 = all->arena.map[adress];
		put_opres(card->regs[args[2]], arg_1, arg_2, op);
		card->curr_pos += (args[1] == DIR_SIZE) ? DIR_SIZE : 2 * IND_SIZE;
	}
}
