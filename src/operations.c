/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/10 15:15:16 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			live(t_general *all, t_card *card, char *args)
{
	int			arg;
	int			t_dir_size;

	arg = 0;
	t_dir_size = 4; // T_DIR size
	card->last_live = all->cycles;
	while (t_dir_size > 0)
	{
		arg += all->arena.map[(card)->curr_pos++];
		t_dir_size--;
	}
	if (arg == card->num)
		all->last_live = get_player(all->players, arg);
}

void			load(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			n_reg;
	int			adress;
	int			i;

	i = 0;
	n_reg = args[1]; // номер регистра получен из первого параметра
	if (*args == T_IND)
	{
		adress = get_arg_value(all, args, i++, 4);
		adress %= IDX_MOD;
		check_val = put_to_reg(all->arena.map,
			&card->regs[n_reg], adress); // ситывает с адреса
		card->carry = (!check_val) ? 1 : 0;
		return ;
	}
	check_val = put_to_reg(all->arena.map,
		&card->regs[n_reg], card->curr_pos); // считывает напрямую
	card->curr_pos += 4;
	card->carry = (!check_val) ? 1 : 0;
}

void			st(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			adress;
	int			n_reg;
	int			i;

	i = 0;
	n_reg = *args;
	check_val = 0;
	if (args[1] == T_REG)
	{
		ft_memcpy((void*)card->regs[args[1]], (void*)card->regs[n_reg], 4);
		return ;
	}
	adress = get_arg_value(all, args, 1, 4);
	adress %= IDX_MOD;
	check_val = set_mem(&all->arena, card->regs[n_reg], adress, 4); // кладет значение регистра по адресу
	card->carry = (!check_val) ? 1 : 0;
}

void			add(t_general *all, t_card *card, char *args)
{
	char		reg_value[4];
	int			check_val;
	int			dst_1;
	int			dst_2;
	int			src;
	int			i;

	i = 0;
	check_val = 0;
	dst_1 = all->arena.map[(card)->curr_pos++];
	dst_2 = all->arena.map[(card)->curr_pos++];
	src = all->arena.map[(card)->curr_pos++];
	while (i < 4)
	{
		card->regs[src][i] = card->regs[dst_1][i] + card->regs[dst_2][i]; // складываю занчения битов
		check_val += card->regs[dst_1][i] + card->regs[dst_2][i];
		i++;
	}
	card->carry = (!check_val) ? 1 : 0;
}

void			sub(t_general *all, t_card *card, char *args)
{
	char		reg_value[4];
	int			check_val;
	int			dst_1;
	int			dst_2;
	int			src;
	int			i;

	i = 0;
	check_val = 0;
	dst_1 = all->arena.map[(card)->curr_pos++];
	dst_2 = all->arena.map[(card)->curr_pos++];
	src = all->arena.map[(card)->curr_pos++];
	while (i < 4)
	{
		card->regs[src][i] = card->regs[dst_1][i] - card->regs[dst_2][i]; // складываю занчения битов
		check_val += card->regs[dst_1][i] - card->regs[dst_2][i];
		i++;
	}
	card->carry = (!check_val) ? 1 : 0;
}

static void		define_bit_op(t_general *all, t_card *card, char *args, char op)
{
	if (args[0] == T_REG)
		bit_op_reg(all, card, args, op);
	else if (args[0] == T_DIR)
		bit_op_dir(all, card, args, op);
	else
		bit_op_in(all, card, args, op);
}

void			and(t_general *all, t_card *card, char *args)
{
	define_bit_op(all, card, args, '&');
}

void			or(t_general *all, t_card *card, char *args)
{
	define_bit_op(all, card, args, '|');
}

void			xor(t_general *all, t_card *card, char *args)
{
	define_bit_op(all, card, args, '^');
}

void			zjmp(t_general *all, t_card *card, char *args)
{
	if (!card->carry)
		return ;
	card->curr_pos += get_arg_value(all, args, 0, 2);
	card->curr_pos %= IDX_MOD;
}

void			ldi(t_general *all, t_card *card, char *args)
{
	int			adress;
	int			r;

	r = args[2];
	adress = get_arg_value(all, args, 0, 2);
	adress += get_arg_value(all, args, 1, 2);
	adress %= IDX_MOD;
	put_to_reg(all->arena.map, &card->regs[r], adress);
	card->curr_pos += count_skiplen(args, 3, 2);
}

void			sti(t_general *all, t_card *card, char *args)
{
	int			adress;
	char		*value;
	int			n_reg;
	int			i;

	i = 1;
	adress = 0;
	n_reg = all->arena.map[(card)->curr_pos]; // номер регистра
	value = card->regs[n_reg - 1];
	while (i < 3)
		adress += get_arg_value(all, args, i++, 2); // Обрабатывает тип аргумента и возращает его числовое значение
	adress %= IDX_MOD; // Это по кукбуку, пока не знаю почему...
	all->arena.set_mem(&all->arena, value, adress, 4); // Записывает значение регистра по адресу
	card->curr_pos += count_skiplen(args, 3, 2);
}

void			fork_m(t_general *all, t_card *card, char *args)
{
	t_card		*card_copy;
	int			adress;
	int			i;

	i = 0;
	adress = get_arg_value(all, args, 0, 2);
	card_copy = (t_card *)ft_memalloc(sizeof(t_card));
	if (!card_copy)
		exit(-1);
	while (i < REG_NUMBER)
	{
		card_copy->regs[i] = ft_memdup(card->regs[i], REG_SIZE);
		i++;
	}
	card_copy->carry = card->carry;
	card_copy->last_live = card->last_live;
	card->curr_pos = adress % IDX_MOD;
	card_copy->next = all->cards;
	all->cards = card_copy;
	card->curr_pos += 2; // DIR_SIZE
}

void			lld(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			n_reg;
	int			adress;
	int			i;

	i = 0;
	n_reg = args[1]; // номер регистра получен из первого параметра
	if (*args == T_IND)
	{
		adress = get_arg_value(all, args, 0, 4);
		check_val = put_to_reg(all->arena.map, &card->regs[n_reg], adress); // ситывает с адреса
		card->carry = (!check_val) ? 1 : 0;
		return ;
	}
	check_val = put_to_reg(all->arena.map, &card->regs[n_reg], card->curr_pos); // считывает напрямую
	card->curr_pos += 4;
	card->carry = (!check_val) ? 1 : 0;
}

void			lldi(t_general *all, t_card *card, char *args)
{
	int			adress;
	int			r;

	r = args[2];
	adress = get_arg_value(all, args, 0, 2);
	adress += get_arg_value(all, args, 1, 2);
	if (args[0] == T_IND || args[1] == T_IND)
		adress %= IDX_MOD;
	put_to_reg(all->arena.map, &card->regs[r], adress);
	card->curr_pos += count_skiplen(args, 3, 2);
}

void			lfork(t_general *all, t_card *card, char *args)
{
	t_card		*card_copy;
	int			adress;
	int			i;

	i = 0;
	adress = get_arg_value(all, args, 0, 2);
	card_copy = (t_card *)ft_memalloc(sizeof(t_card));
	if (!card_copy)
		exit(-1);
	while (i < REG_NUMBER)
	{
		card_copy->regs[i] = ft_memdup(card->regs[i], REG_SIZE);
		i++;
	}
	card_copy->carry = card->carry;
	card_copy->last_live = card->last_live;
	card_copy->next = all->cards;
	all->cards = card_copy;
	card->curr_pos += 2; // DIR_SIZE
}

void			aff(t_general *all, t_card *card, char *args)
{
	char		c;
	int			r;
	int			value;

	r = all->arena.map[card->curr_pos];
	value = get_arg_value(all, card->regs[r], 0, 2);
	c = (char)(value % 256);
	write(1, &(c), 1);
	card->curr_pos += 1;
}

void			add_op_links(t_general *all)
{
	all->operations[0] = &live;
	all->operations[1] = &load;
	all->operations[2] = &st;
	all->operations[3] = &add;
	all->operations[4] = &sub;
	all->operations[5] = &and;
	all->operations[6] = &or;
	all->operations[7] = &xor;
	all->operations[8] = &zjmp;
	all->operations[9] = &ldi;
	all->operations[10] = &sti;
	all->operations[11] = &fork_m;
	all->operations[12] = &lld;
	all->operations[13] = &lldi;
	all->operations[14] = &lfork;
	all->operations[15] = &aff;
}

// Обернуть передвижение картеки в функции: int cursor_next(int cursor) && int cursor_change(int cursor)
