/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 09:23:55 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:14:33 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void		log_zjmp(int card_num, int adress, bool carry)
{
	ft_printf("P %4d | zjmp %d %s\n", card_num, adress, (carry)
		? "OK" : "FAILED");
}

void			zjmp(t_general *all, t_card *card)
{
	int			cursor_update;

	cursor_update = get_twobytes(all->arena, card->cursor + card->steps);
	if (!card->carry)
	{
		card->steps += card->op->t_dir_size;
		if (all->flag_v & SHOW_OPERATIONS)
			log_zjmp(card->num, cursor_update, card->carry);
		return ;
	}
	card->cursor = cursor_to(card->cursor + cursor_update % IDX_MOD);
	card->steps = 0;
	if (all->flag_v & SHOW_OPERATIONS)
		log_zjmp(card->num, cursor_update, card->carry);
}
