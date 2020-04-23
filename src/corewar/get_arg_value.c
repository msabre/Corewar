/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:11:07 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:10:53 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int	get_point_aress(unsigned char *arena, t_card *card, bool mod)
{
	int		adress;

	adress = get_twobytes(arena, card->cursor + card->steps);
	adress = (mod) ? adress % IDX_MOD : adress;
	adress = cursor_to(card->cursor + adress);
	card->steps += IND_SIZE;
	return (adress);
}

int			get_arg_value(unsigned char *arena,
			t_card *card, int num, bool mod)
{
	int		dir_size;
	int		value;
	int		size;
	int		adress;

	dir_size = card->op->t_dir_size;
	adress = card->cursor + card->steps;
	if (card->args[num] == T_REG)
	{
		card->steps += 1;
		value = get_char(arena, adress) - 1;
		return (card->regs[value]);
	}
	if (card->args[num] == T_IND)
		adress = get_point_aress(arena, card, mod);
	else
		card->steps += dir_size;
	size = (card->args[num] == T_DIR) ? dir_size : 4;
	if (size == 4)
		value = get_fourbytes(arena, adress);
	else
		value = get_twobytes(arena, adress);
	return (value);
}

int			get_nreg(unsigned char *arena, t_card *card)
{
	int		nreg;
	int		pos;

	pos = card->cursor + card->steps;
	nreg = get_char(arena, pos) - 1;
	card->steps += 1;
	return (nreg);
}
