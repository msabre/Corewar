/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:59 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/07 14:12:41 by andrejskobe      ###   ########.fr       */
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
	// write(1, all->arena.map, 4096);
}
