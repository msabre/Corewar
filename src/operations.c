/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/22 13:02:49 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			live(t_general *all, t_card *card)
{
	int			value;

	all->n_live_op++;
	card->alive_cycle = all->cycles;
	value = get_fourbytes(&all->arena, card->cursor + card->steps);
	card->steps += 4;
	if (value * (-1) == card->num)
		all->last_live = card->player;
}

void			load(t_general *all, t_card *card)
{
	int			value;
	int			r;

	value = get_arg_value(&all->arena, card, 0, true);
	r = get_nreg(&all->arena, card, 1);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? 1 : 0;
}

void			st(t_general *all, t_card *card)
{
	int			adress;
	int			value;
	int			r;

	r = get_nreg(&all->arena, card, 0);
	if (card->args[1] == REG_CODE)
	{
	 	value = get_nreg(&all->arena, card, 1);
		card->regs[value] = card->regs[r];
		card->carry = (!card->regs[value]) ? 1 : 0;
		return ;
	}
	else if (card->args[1] == IND_CODE)
	{
		adress = card->cursor + card->steps;
		adress = get_twobytes(&all->arena, adress);
		adress += card->cursor;
		card->steps += IND_SIZE;
	}
	else
		adress = get_arg_value(&all->arena, card, 1, true);
	card->carry = (!value) ? true : false;
	set_reg(&all->arena, card->regs[r], adress);
}

void			add(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, false);
	arg_2 = get_arg_value(&all->arena, card, 1, false);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 + arg_2;
	card->carry = (!card->regs[r]) ? true : false;
}

void			sub(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, false);
	arg_2 = get_arg_value(&all->arena, card, 1, false);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 - arg_2;
	card->carry = (!card->regs[r]) ? true : false;
}

void			and(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, true);
	arg_2 = get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 & arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
}

void			or(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, true);
	arg_2 = get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 | arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
}

void			xor(t_general *all, t_card *card)
{
	int			arg_1;
	int			arg_2;
	int			r;

	arg_1 = get_arg_value(&all->arena, card, 0, true);
	arg_2 = get_arg_value(&all->arena, card, 1, true);
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = arg_1 ^ arg_2;
	card->carry = (!card->regs[r]) ? 1 : 0;
}

void			zjmp(t_general *all, t_card *card)
{
	int			cursor_update;

	if (!card->carry)
	{
		card->steps += card->op->t_dir_size;
		return ;
	}
	cursor_update = get_twobytes(&all->arena, card->cursor + card->steps);
	cursor_update %= IDX_MOD;
	cursor_update += card->cursor;
	card->steps = 0;
	card->cursor = cursor_to(cursor_update);
}

void			ldi(t_general *all, t_card *card)
{
	int			adress;
	int			r;

	adress = get_arg_value(&all->arena, card, 0, true);
	adress += get_arg_value(&all->arena, card, 1, true);
	adress %= IDX_MOD;
	adress += card->cursor;
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = (unsigned int)get_fourbytes(&all->arena, adress);
}

void				sti(t_general *all, t_card *card)
{
	int				adress;
	int				value;

	adress = 0;
	value = get_arg_value(&all->arena, card, 0, false);
	adress = get_arg_value(&all->arena, card, 1, true);
	adress += get_arg_value(&all->arena, card, 2, true);
	adress %= IDX_MOD;
	adress += card->cursor;
	set_reg(&all->arena, value, adress);
}

void			fork_m(t_general *all, t_card *card)
{
	t_card		*new;
	int			adress;
	int			i;

	adress = get_twobytes(&all->arena, card->cursor + card->steps);
	adress %= IDX_MOD;
	card->steps += 2;
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	i = -1;
	while (++i < REG_NUMBER)
		new->regs[i] = card->regs[i];
	new->carry = card->carry;
	new->alive_cycle = card->alive_cycle;
	new->cursor = cursor_to(card->cursor + adress);
	new->next = all->cards;
	new->steps = 0;
	new->num = all->current_card_num++;
	all->cards = new;
}

void			lld(t_general *all, t_card *card)
{
	int			value;
	int			r;

	value = get_arg_value(&all->arena, card, 0, false);
	r = get_nreg(&all->arena, card, 1);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? 1 : 0;
}

void			lldi(t_general *all, t_card *card)
{
	int			adress;
	int			r;

	adress = get_arg_value(&all->arena, card, 0, true);
	adress += get_arg_value(&all->arena, card, 1, true);
	adress += card->cursor;
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = (unsigned int)get_fourbytes(&all->arena, adress);
}

void			lfork(t_general *all, t_card *card)
{
	t_card		*new;
	int			adress;
	int			i;

	adress = get_twobytes(&all->arena, card->cursor + card->steps);
	card->steps += 2;
	new = (t_card *)ft_memalloc(sizeof(t_card));
	if (!new)
		exit(-1);
	i = -1;
	while (++i < REG_NUMBER)
		new->regs[i] = card->regs[i];
	new->carry = card->carry;
	new->alive_cycle = card->alive_cycle;
	new->cursor = cursor_to(card->cursor + adress);
	new->next = all->cards;
	new->steps = 0;
	new->num = all->current_card_num++;
	all->cards = new;
}

void			aff(t_general *all, t_card *card)
{
	char		c;
	int			r;
	int			value;

	r = get_char(&all->arena, card->cursor + card->steps) - 1;
	value = card->regs[r];
	c = (char)(value % 256);
	write(1, &(c), 1);
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
