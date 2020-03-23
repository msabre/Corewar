/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/23 11:38:54 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		log_live(int card_num, int player_num)
{
	ft_printf("P %4d | live %d\n", card_num, player_num);
}

void			live(t_general *all, t_card *card)
{
	int			value;

	all->n_live_op++;
	card->alive_cycle = all->cycles;
	value = get_fourbytes(&all->arena, card->cursor + card->steps);
	card->steps += 4;
	if (value * (-1) == card->num)
		all->last_live = card->player;
	if (all->flag_v)
		log_live(card->num, all->players->num);
}

static void		log_load(int card_num, int value, int r)
{
	ft_printf("P %4d | ld %d r%d\n", card_num, value, r);
}

void			load(t_general *all, t_card *card)
{
	int			value;
	int			r;

	value = get_arg_value(&all->arena, card, 0, true);
	r = get_nreg(&all->arena, card, 1);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? 1 : 0;
	if (all->flag_v)
		log_load(card->num, value, r);
}

static void		log_st(int cursor_id, int r, int adress)
{
	ft_printf("P %4d | st r%d %d\n", cursor_id, r, adress);
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
	if (all->flag_v)
		log_st(card->num, r, adress);
}

static void		log_add(int card_num, int r1, int r2, int r3)
{
	ft_printf("P %4d | add r%d r%d r%d\n", card_num, r1, r2, r3);
}

void			add(t_general *all, t_card *card)
{
	int			r1;
	int			r2;
	int			r3;

	r1 = get_nreg(&all->arena, card, 0);
	r2 = get_nreg(&all->arena, card, 1);
	r3 = get_nreg(&all->arena, card, 2);
	card->regs[r3] = card->regs[r1] + card->regs[r2];
	card->carry = (!card->regs[r3]) ? true : false;
	if (all->flag_v)
		log_add(card->num, r1, r2, r3);
}

static void		log_sub(int card_num, int r1, int r2, int r3)
{
	ft_printf("P %4d | sub r%d r%d r%d\n", card_num, r1, r2, r3);
}

void			sub(t_general *all, t_card *card)
{
	int			r1;
	int			r2;
	int			r3;

	r1 = get_nreg(&all->arena, card, 0);
	r2 = get_nreg(&all->arena, card, 1);
	r3 = get_nreg(&all->arena, card, 2);
	card->regs[r3] = card->regs[r1] - card->regs[r2];
	card->carry = (!card->regs[r3]) ? true : false;
	if (all->flag_v)
		log_sub(card->num, r1, r2, r3);
}

static void		log_and(int card_num, int arg_1, int arg_2, int r)
{
	ft_printf("P %4d | and %d %d r%d\n", card_num, arg_1, arg_2, r);
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
	if (all->flag_v)
		log_and(card->num, arg_1, arg_2, r);
}

static void		log_or(int card_num, int arg_1, int arg_2, int r)
{
	ft_printf("P %4d | or %d %d r%d\n", card_num, arg_1, arg_2, r);
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
	if (all->flag_v)
		log_or(card->num, arg_1, arg_2, r);
}

static void		log_xor(int card_num, int arg_1, int arg_2, int r)
{
	ft_printf("P %4d | xor %d %d r%d\n", card_num, arg_1, arg_2, r);
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
	if (all->flag_v)
		log_xor(card->num, arg_1, arg_2, r);
}

static void		log_zjmp(int card_num, int adress, bool carry)
{
	ft_printf("P %4d | zjmp %d %s\n", card_num, adress, (carry) ? "OK" : "FAILED");
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
	if (all->flag_v)
		log_zjmp(card->num, card->cursor, card->carry);
}

static void		log_ldi(t_card *card, int adress_1, int adress_2, int r)
{
	ft_printf("P %4d | ldi %d %d r%d\n", card->num, adress_1, adress_2, r);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
		adress_1, adress_2, adress_1 + adress_2,
			card->cursor + (adress_1 + adress_2) % IDX_MOD);
}

void			ldi(t_general *all, t_card *card)
{
	int			adress_1;
	int			adress_2;
	int			adress;
	int			r;

	adress_1 = get_arg_value(&all->arena, card, 0, true);
	adress_2 = get_arg_value(&all->arena, card, 1, true);
	adress = (adress_1 + adress_2) % IDX_MOD;
	adress += card->cursor;
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = (unsigned int)get_fourbytes(&all->arena, adress);
	if (all->flag_v)
		log_ldi(card, adress_1, adress_2, r);
}

static void		log_sti(t_card *card, int adress_1, int adress_2, int r)
{
	ft_printf("P %4d | sti r%d %d %d\n", card->num, r, adress_1, adress_2);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		adress_1, adress_2, adress_1 + adress_2,
			card->cursor + ((adress_1 + adress_2) % IDX_MOD));
}

void			sti(t_general *all, t_card *card)
{
	int			adress_1;
	int			adress_2;
	int			adress;
	int			value;
	int			r;

	r = get_nreg(&all->arena, card, 0);
	value = card->regs[r];
	adress_1 = get_arg_value(&all->arena, card, 1, true);
	adress_2 = get_arg_value(&all->arena, card, 2, true);
	adress = (adress_1 + adress_2) % IDX_MOD;
	adress += card->cursor;
	set_reg(&all->arena, value, adress);
	if (all->flag_v)
		log_ldi(card, adress_1, adress_2, r);
}

static void		log_fork_m(int card_num, int card_cursor, int adress)
{
	ft_printf("P %4d | fork %d (%d)\n", card_num, adress,
		card_cursor + adress % IDX_MOD);
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
	if (all->flag_v)
		log_fork_m(card->num, card->cursor, adress);
}

static void		log_lld(int card_num, int value, int r)
{
	ft_printf("P %4d | lld %d r%d\n", card_num, value, r);
}

void			lld(t_general *all, t_card *card)
{
	int			value;
	int			r;

	value = get_arg_value(&all->arena, card, 0, false);
	r = get_nreg(&all->arena, card, 1);
	card->regs[r] = value;
	card->carry = (!card->regs[r]) ? 1 : 0;
	if (all->flag_v)
		log_lld(card->num, value, r);
}

static void		log_lldi(t_card *card, int adress_1, int adress_2, int r)
{
	ft_printf("P %4d | lldi %d %d r%d\n", card->num, adress_1, adress_2, r);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
		adress_1, adress_2, adress_1 + adress_2,
			card->cursor + adress_1 + adress_2);
}

void			lldi(t_general *all, t_card *card)
{
	int			adress_1;
	int			adress_2;
	int			adress;
	int			r;

	adress_1 = get_arg_value(&all->arena, card, 0, true);
	adress_2 = get_arg_value(&all->arena, card, 1, true);
	adress = adress_1 + adress_2;
	adress += card->cursor;
	r = get_nreg(&all->arena, card, 2);
	card->regs[r] = (unsigned int)get_fourbytes(&all->arena, adress);
	if (all->flag_v)
		log_lldi(card, adress_1, adress_2, r);
}

static void		log_lfork(int card_num, int card_cursor, int adress)
{
	ft_printf("P %4d | lfork %d (%d)\n", card_num, adress,
		card_cursor + adress);
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
	if (all->flag_v)
		log_lfork(card->num, card->cursor, adress);
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
