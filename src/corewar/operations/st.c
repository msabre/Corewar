/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:19:14 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 22:08:35 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_st(int cursor_id, int r, int adress)
{
	ft_printf("P %4d | st r%d %d\n", cursor_id, r, adress);
}

void			st(t_general *all, t_card *card)
{
	int			adress;
	int			value;
	int			r;

	r = get_nreg(all->arena, card);
	if (card->args[1] == T_REG)
	{
		value = get_nreg(all->arena, card);
		card->regs[value] = card->regs[r];
		if (all->flag_v & SHOW_OPERATIONS)
			log_st(card->num, r + 1, value + 1);
		return ;
	}
	else if (card->args[1] == T_IND)
	{
		adress = card->cursor + card->steps;
		adress = get_twobytes(all->arena, adress);
		card->steps += IND_SIZE;
	}
	else
		adress = get_arg_value(all->arena, card, 1, true);
	set_reg(all->arena, card->regs[r], (adress % IDX_MOD)
		+ (card->args[1] & T_IND ? card->cursor : 0));
	if (all->flag_v & SHOW_OPERATIONS)
		log_st(card->num, r + 1, adress);
}
