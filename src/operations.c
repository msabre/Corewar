/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/11 15:11:49 by andrejskobe      ###   ########.fr       */
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
		arg += all->arena.map[(card)->cursor];
		card->cursor = cursor_next(card->cursor);
		t_dir_size--;
	}
	if (arg == card->num)
		all->last_live = get_player(all->players, arg);
}

void			load(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			r_adress;
	int			r;
	int			adress;
	int			i;

	i = 0;
	r_adress = card->cursor + count_skiplen(args, 1, 4);
	r = (all->arena).map[r_adress] - 1; // номер регистра получен из первого параметра
	if (*args == T_IND)
	{
		adress = get_arg_value(all, args, i++, 4);
		adress %= IDX_MOD;
		check_val = put_to_reg(all->arena.map,
			&card->regs[r], adress); // ситывает с адреса
		card->carry = (!check_val) ? 1 : 0;
		return ;
	}
	check_val = put_to_reg(all->arena.map,
		&card->regs[r], card->cursor); // считывает напрямую
	card->cursor = cursor_steps(card->cursor, 4);
	card->carry = (!check_val) ? 1 : 0;
}

void			st(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			adress;
	int			r;
	int			i;

	i = 0;
	r = (all->arena).map[card->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	check_val = 0;
	if (args[1] == T_REG)
	{
		adress = (all->arena).map[card->cursor] - 1;
		card->cursor = cursor_next(card->cursor);
		ft_memcpy((void*)card->regs[adress], (void*)card->regs[r], 4);
		return ;
	}
	adress = get_arg_value(all, args, 1, 4);
	adress %= IDX_MOD;
	check_val = set_mem(&all->arena, card->regs[r], adress, 4); // кладет значение регистра по адресу
	card->cursor = cursor_steps(card->cursor, 2);
	card->carry = (!check_val) ? 1 : 0;
}

void			add(t_general *all, t_card *card, char *args)
{
	char		reg_value[4];
	int			check_val;
	int			r_1;
	int			r_2;
	int			src;
	int			i;

	i = 0;
	check_val = 0;
	r_1 = all->arena.map[(card)->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	r_2 = all->arena.map[(card)->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	src = all->arena.map[(card)->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	while (i < 4)
	{
		card->regs[src][i] = card->regs[r_1][i] + card->regs[r_2][i]; // складываю занчения битов
		check_val += card->regs[r_1][i] + card->regs[r_2][i];
		i++;
	}
	card->carry = (!check_val) ? 1 : 0;
}

void			sub(t_general *all, t_card *card, char *args)
{
	char		reg_value[4];
	int			check_val;
	int			r_1;
	int			r_2;
	int			src;
	int			i;

	i = 0;
	check_val = 0;
	r_1 = all->arena.map[(card)->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	r_2 = all->arena.map[(card)->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	src = all->arena.map[(card)->cursor] - 1;
	card->cursor = cursor_next(card->cursor);
	while (i < 4)
	{
		card->regs[src][i] = card->regs[r_1][i] - card->regs[r_2][i]; // складываю занчения битов
		check_val += card->regs[r_1][i] - card->regs[r_2][i];
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
	int			cursor_update;

	if (!card->carry)
		return ;
	cursor_update = card->cursor + get_arg_value(all, args, 0, 2);
	cursor_update %= IDX_MOD;
	card->cursor = cursor_to(cursor_update);
}

void			ldi(t_general *all, t_card *card, char *args)
{
	int			cursor_update;
	int			r_adress;
	int			adress;
	int			r;

	r_adress = card->cursor + count_skiplen(args, 2, 2); // позиция регистра #3 аргумент
	r = all->arena.map[r_adress] - 1; // считываем 1 байт - номер регистра
	adress = get_arg_value(all, args, 0, 2);
	adress += get_arg_value(all, args, 1, 2);
	adress %= IDX_MOD;
	put_to_reg(all->arena.map, &card->regs[r], adress);
	cursor_update = card->cursor + count_skiplen(args, 3, 2); // новая позтиция курсора
	card->cursor = cursor_to(cursor_update);
}

void				sti(t_general *all, t_card *card, char *args)
{
	int				adress;
	int				cursor_update;
	unsigned char	*value;
	int				r;
	int				i;

	i = 1;
	adress = 0;
	r = all->arena.map[(card)->cursor] - 1; // номер регистра
	value = card->regs[r];
	while (i < 3)
		adress += get_arg_value(all, args, i++, 2); // Обрабатывает тип аргумента и возращает его числовое значение
	adress %= IDX_MOD; // Это по кукбуку, пока не знаю почему...
	(all->arena).set_mem(&all->arena, value, adress, 4); // Записывает значение регистра по адресу
	cursor_update = card->cursor + count_skiplen(args, 3, 2);
	card->cursor = cursor_to(cursor_update);
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
	card_copy->regs = (unsigned char **)malloc(sizeof(unsigned char *));
	if (!card_copy->regs)
		exit(-1);
	while (i < REG_NUMBER)
	{
		card_copy->regs[i] = ft_memdup(card->regs[i], REG_SIZE);
		i++;
	}
	card_copy->carry = card->carry;
	card_copy->last_live = card->last_live;
	card_copy->cursor = cursor_to(adress) % IDX_MOD;
	card_copy->next = all->cards;
	all->cards = card_copy;
	card->cursor = cursor_steps(card->cursor, 2); // DIR_SIZE
}

void			lld(t_general *all, t_card *card, char *args)
{
	int			r_adress;
	int			check_val;
	int			r;
	int			adress;
	int			i;

	i = 0;
	r_adress = card->cursor + count_skiplen(args, 1, 2);
	r = (all->arena).map[r_adress] - 1; // номер регистра получен из первого параметра
	if (*args == T_IND)
	{
		adress = get_arg_value(all, args, 0, 4);
		check_val = put_to_reg(all->arena.map, &card->regs[r], adress); // ситывает с адреса
		card->carry = (!check_val) ? 1 : 0;
		return ;
	}
	check_val = put_to_reg(all->arena.map, &card->regs[r], card->cursor); // считывает напрямую
	card->cursor += 4;
	card->carry = (!check_val) ? 1 : 0;
}

void			lldi(t_general *all, t_card *card, char *args)
{
	int			r_adress;
	int			cursor_update;
	int			adress;
	int			r;

	r_adress = card->cursor + count_skiplen(args, 1, 2);
	r = (all->arena).map[r_adress] - 1; // номер регистра получен из первого параметра
	adress = get_arg_value(all, args, 0, 2);
	adress += get_arg_value(all, args, 1, 2);
	if (args[0] == T_IND || args[1] == T_IND)
		adress %= IDX_MOD;
	put_to_reg(all->arena.map, &card->regs[r], adress);
	cursor_update = card->cursor + count_skiplen(args, 3, 2);
	card->cursor = cursor_to(cursor_update);
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
	card_copy->regs = (unsigned char **)malloc(sizeof(unsigned char *));
	if (!card_copy->regs)
		exit(-1);
	while (i < REG_NUMBER)
	{
		card_copy->regs[i] = ft_memdup(card->regs[i], REG_SIZE);
		i++;
	}
	card_copy->carry = card->carry;
	card_copy->last_live = card->last_live;
	card_copy->next = all->cards;
	card_copy->cursor = cursor_to(adress);
	all->cards = card_copy;
	card->cursor = cursor_steps(card->cursor, 4); // DIR_SIZE
}

void			aff(t_general *all, t_card *card, char *args)
{
	char		c;
	int			r;
	int			value;

	r = all->arena.map[card->cursor] - 1;
	value = get_arg_value(all, args, 0, 2);
	c = (char)(value % 256);
	write(1, &(c), 1);
	card->cursor = cursor_next(card->cursor);
}

void			add_op_links(t_general *all)
{
	all->operations[0] = live;
	all->operations[1] = load;
	all->operations[2] = st;
	all->operations[3] = add;
	all->operations[4] = sub;
	all->operations[5] = and;
	all->operations[6] = or;
	all->operations[7] = xor;
	all->operations[8] = zjmp;
	all->operations[9] = ldi;
	all->operations[10] = sti;
	all->operations[11] = fork_m;
	all->operations[12] = lld;
	all->operations[13] = lldi;
	all->operations[14] = lfork;
	all->operations[15] = aff;
}
