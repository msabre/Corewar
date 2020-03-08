/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/08 15:05:20 by andrejskobe      ###   ########.fr       */
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

void			ld(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			n_reg;
	int			adress;
	int			i;

	i = 0;
	n_reg = args[1]; // номер регистра получен из первого параметра
	if (*args == T_IND)
	{
		adress = get_arg_value(&all->arena, card, args[i++], 4);
		adress %= IDX_MOD;
		check_val = put_to_reg(all->arena.map, &card->regs[n_reg], adress); // ситывает с адреса
		card->carry = (!check_val) ? 1 : 0;
		return ;
	}
	check_val = put_to_reg(all->arena.map, &card->regs[n_reg], card->curr_pos); // считывает напрямую
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
	adress = get_arg_value(&all->arena, card, args[1], 4);
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

void			and(t_general *all, t_card *card, char *args)
{
	int			check_val;
	int			reg1;
	int			reg2;
	int			i;

	check_val = 0;
	if (args[0] == T_REG)
	{
		reg1 = all->arena.map[(card)->curr_pos++];
		if (args[1] == T_REG)
		{
			reg2 = all->arena.map[(card)->curr_pos++];
			while (i < 4)
			{
				card->regs[args[2]][i] = card->regs[reg1][i] & card->regs[reg2][i];
				check_val += card->regs[reg1][i] & card->regs[reg2][i];
				i++;
			}
		}
		else if (args[1] == DIR_SIZE)
			check_val = put_to_reg(all->arena.map, card->regs[reg1], card->curr_pos);
		else if ()
			// считать в регистр с адреса
	}
}

void			sti(t_general *all, t_card *card, char *args)
{
	int			adress;
	char		*value;
	int			n_reg;
	int			i;

	i = 1;
	adress = 0;
	n_reg = all->arena.map[(card)->curr_pos++]; // номер регистра
	value = card->regs[n_reg - 1];
	while (i < 3)
		adress += get_arg_value(&all->arena, card, args[i++], 2); // Обрабатывает тип аргумента и возращает его числовое значение
	adress %= IDX_MOD; // Это по кукбуку, пока не знаю почему...
	all->arena.set_mem(&all->arena, value, adress, 4); // Записывает значение регистра по адресу
	write(1, all->arena.map, 4096);
}
