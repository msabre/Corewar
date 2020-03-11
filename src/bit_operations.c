/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:23:30 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/11 14:05:14 by andrejskobe      ###   ########.fr       */
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

static void	put_opres(unsigned char *dst, unsigned char *arg1, unsigned char *arg2, char op)
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
	int		steps_forward;
	unsigned char	*arg_1;
	unsigned char	*arg_2;

	arg_1 = card->regs[r];
	r = all->arena.map[(card)->cursor];
	if (args[1] == T_REG)
	{
		adress = all->arena.map[(card)->cursor];
		arg_2 = card->regs[adress];
		put_opres(card->regs[r], arg_1, arg_2, op);
	}
	else
	{
		if (args[1] == T_DIR)
			adress = card->cursor;
		else
			adress = get_arg_value(all, args, 1, 4);
		arg_2 = &all->arena.map[adress];
		put_opres(card->regs[r], arg_1, arg_2, op);
		steps_forward = (args[0] == T_DIR) ? DIR_SIZE : IND_SIZE;
		card->cursor = cursor_steps(card->cursor, steps_forward);
	}
}

void		bit_op_dir(t_general *all, t_card *card, char *args, char op)  // 25 строки
{
	int		steps_forward;
	int		adress;
	unsigned char	*arg_1;
	unsigned char	*arg_2;
	int		r;

	adress = card->cursor + count_skiplen(args, 2, 4);
	r = (all->arena).map[adress] - 1;
	arg_1 = &all->arena.map[card->cursor]; // указатель на память T_DIR, по ней будет идти считывание 4 байта
	if (args[1] == T_REG)
	{
		adress = all->arena.map[card->cursor + DIR_SIZE] - 1; // номер регистра
		arg_2 = card->regs[adress];
		put_opres(card->regs[r], arg_1, arg_2, op);
		card->cursor = cursor_steps(card->cursor, REG_SIZE);
	}
	else
	{
		if (args[1] == T_DIR)
			adress = card->cursor + DIR_SIZE;
		else
			adress = get_arg_value(all, args, 1, 4);
		arg_2 = &all->arena.map[adress];
		put_opres(card->regs[r], arg_1, arg_2, op);
		steps_forward = (args[0] == T_DIR) ? DIR_SIZE : IND_SIZE;
		card->cursor = cursor_steps(card->cursor, steps_forward); // Проверено
	}
}

void		bit_op_in(t_general *all, t_card *card, char *args, char op) // 23 строки
{
	unsigned char	*arg_1;
	unsigned char	*arg_2;
	int		adress;
	int		steps_forward;
	int		r;

	adress = card->cursor + count_skiplen(args, 2, 4);
	r = (all->arena).map[adress] - 1;
	adress = get_arg_value(all, args, 0, 4);
	arg_1 = &all->arena.map[adress];
	if (args[1] == T_REG)
	{
		adress = all->arena.map[card->cursor + IND_SIZE];
		arg_2 = card->regs[adress];
		put_opres(card->regs[r], arg_1, arg_2, op);
		steps_forward = IND_SIZE + REG_SIZE;
		card->cursor = cursor_steps(card->cursor, steps_forward); // Проверено
	}
	else
	{
		if (args[1] == DIR_SIZE)
			adress += IND_SIZE;
		else
			adress += get_arg_value(all, args, 1, 4);
		arg_2 = &all->arena.map[adress];
		put_opres(card->regs[r], arg_1, arg_2, op);
		steps_forward = card->cursor;
		steps_forward += (args[1] == DIR_SIZE) ? DIR_SIZE : 2 * IND_SIZE;
		card->cursor = cursor_steps(card->cursor, steps_forward);
	}
}
