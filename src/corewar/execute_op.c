/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:41:40 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 15:21:27 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int			calc_nargs(char *args, t_op *op, int n)
{
	int				args_len;
	int				i;

	i = 0;
	args_len = 0;
	while (i < op->argc && i < n)
	{
		if (args[i] & T_REG)
			args_len += 1;
		else if (args[i] & T_IND)
			args_len += IND_SIZE;
		else if (args[i] & T_DIR)
			args_len += op->t_dir_size;
		i++;
	}
	return (args_len);
}

static int			is_args_type(t_op *operation)
{
	if (operation->argc == 1 && operation->argv[0] & T_DIR)
		return (0);
	return (1);
}

static int			valid_arg(unsigned char *arena, t_card *card)
{
	char			a;
	int				r_num;
	int				r_adress;
	int				i;

	i = -1;
	while (++i < card->op->argc)
	{
		a = card->args[i] & card->op->argv[i];
		if (a == T_REG)
		{
			r_adress = card->cursor + card->steps;
			r_adress += calc_nargs(card->args, card->op, i);
			r_num = get_char(arena, r_adress);
			if (r_num < 1 || r_num > 16)
				return (0);
		}
		if (!(a & T_REG || a & T_DIR || a & T_IND))
			return (0);
	}
	return (1);
}

static void			get_types(t_card *card, unsigned char read_byte,
					unsigned char *arg_types)
{
	int				shift;
	int				i;

	i = -1;
	shift = 6;
	while (++i < card->op->argc)
	{
		card->args[i] = arg_types[((read_byte >> shift) & 3) - 1];
		shift -= 2;
	}
}

void				check_args_and_exe_op(t_general *all, t_card *card)
{
	unsigned char	read_byte;

	card->steps += 1;
	read_byte = get_char(all->arena, card->cursor + card->steps);
	if (is_args_type(card->op))
	{
		card->steps += 1;
		ft_bzero(card->args, 4);
		get_types(card, read_byte, all->arg_types);
		if (!valid_arg(all->arena, card))
		{
			card->steps += calc_nargs(card->args, card->op, card->op->argc);
			return ;
		}
	}
	all->operations[card->code_op - 1](all, card);
}
