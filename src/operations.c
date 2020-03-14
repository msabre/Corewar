/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/13 12:26:18 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			live(t_general *all, t_card *card)
{
	int			value;

	all->n_live_op++;
	card->alive_cycle = all->cycles;
	value = get_arg_value(&all->arena, card, 0, card->op->t_dir_size);
	if (value * (-1) == card->num)
		all->last_live = card->player;
	card->cursor = cursor_steps(card->cursor, 4);
}

void			load(t_general *all, t_card *card)
{
	int			skiplen;
	int			value;
	int			r;

	r = get_nreg(&all->arena, card, 1);
	value = get_arg_value(&all->arena, card, 0, true);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? 1 : 0;
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			st(t_general *all, t_card *card)
{
	int			value;
	int			r;

	r = get_nreg(&all->arena, card, 0);
	if (card->args[1] == REG_CODE)
	{
	 	value = get_nreg(&all->arena, card, 0);
		card->regs[value] = card->regs[r];
		card->carry = (!card->regs[value]) ? 1 : 0;
		return ;
	}
	value = get_arg_value(&all->arena, card, 1, true) - 1;
	value += card->cursor;
	card->carry = (!value) ? true : false;
	set_reg(&all->arena, card->regs[r], value);
	card->cursor = cursor_steps(card->cursor, IND_SIZE + T_REG); // REG_SIZE
}

void			add(t_general *all, t_card *card)
{
	int			skiplen;
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, false);
	arg_2 = get_arg_value(&all->arena, card, 1, false);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 + arg_2;
	card->carry = (!card->regs[r]) ? true : false;
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			sub(t_general *all, t_card *card)
{
	int			skiplen;
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, false);
	arg_2 = get_arg_value(&all->arena, card, 1, false);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 - arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			and(t_general *all, t_card *card)
{
	int			skiplen;
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, true);
	arg_2 = get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 & arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			or(t_general *all, t_card *card)
{
	int			skiplen;
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, true);
	arg_2 = get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 | arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			xor(t_general *all, t_card *card)
{
	int			skiplen;
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, true);
	arg_2 = get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 ^ arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			zjmp(t_general *all, t_card *card)
{
	int			cursor_update;

	if (!card->carry)
		return ;
	cursor_update = get_arg_value(&all->arena, card, 0, true);
	cursor_update %= IDX_MOD;
	cursor_update += card->cursor;
	card->cursor = cursor_to(cursor_update - 1);
}

void			ldi(t_general *all, t_card *card)
{
	int			skiplen;
	int			adress;
	int			r;

	adress = get_arg_value(&all->arena, card, 0, true);
	adress += get_arg_value(&all->arena, card, 1, true);
	adress %= IDX_MOD;
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = get_bytes(&all->arena, adress, 4);
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen); // после этой функции проблема
}

void				sti(t_general *all, t_card *card)
{
	int				skiplen;
	int				adress;
	int				value;

	adress = 0;
	value = get_arg_value(&all->arena, card, 0, false);
	adress = get_arg_value(&all->arena, card, 1, true);
	adress += get_arg_value(&all->arena, card, 2, true);
	adress %= IDX_MOD;
	adress += card->cursor - 1; // -1
	set_reg(&all->arena, value, adress);
	skiplen = count_skiplen(card, 3);
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			fork_m(t_general *all, t_card *card)
{
	t_card		*new;
	int			skiplen;
	int			adress;
	int			i;

	adress = get_arg_value(&all->arena, card, 0, true);
	adress %= IDX_MOD;
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	i = -1;
	while (++i < REG_NUMBER)
		new->regs[i] = card->regs[i];
	new->carry = card->carry;
	new->alive_cycle = card->alive_cycle;
	new->cursor = cursor_to(adress);
	new->next = all->cards;
	all->cards = new;
	skiplen = card->op->t_dir_size;
	card->cursor = cursor_steps(card->cursor, skiplen);
}

void			lld(t_general *all, t_card *card)
{
	int			value;
	int			r;

	r = get_nreg(&all->arena, card,1);
	value = get_arg_value(&all->arena, card, 0, false);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? 1 : 0;
	card->cursor = cursor_steps(card->cursor, 4);
}

void			lldi(t_general *all, t_card *card)
{
	int			skiplen;
	int			adress;
	int			r;

	adress = get_arg_value(&all->arena, card, 0, true);
	adress += get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = get_bytes(&all->arena, adress, 4);
	skiplen = count_skiplen(card, 3);
	cursor_steps(card->cursor, skiplen);
}

void			lfork(t_general *all, t_card *card)
{
	t_card		*new;
	int			adress;
	int			i;

	adress = get_arg_value(&all->arena, card, 0, 2);
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	i = -1;
	while (++i < REG_NUMBER)
		new->regs[i] = card->regs[i];
	new->carry = card->carry;
	new->alive_cycle = card->alive_cycle;
	new->cursor = cursor_to(adress);
	new->next = all->cards;
	all->cards = new;
	card->cursor = cursor_steps(card->cursor, 2); // DIR_SIZE
}

void			aff(t_general *all, t_card *card)
{
	char		c;
	int			value;

	value = get_arg_value(&all->arena, card, 0, 2);
	c = (char)(value % 256);
	write(1, &(c), 1);
	card->cursor = cursor_next(card->cursor);
}

void			get_op_links(t_general *all)
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
