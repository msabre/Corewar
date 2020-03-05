/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:23:51 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 17:15:56 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

static void		put_box(int num, t_player *player, t_player *head)
{
	int 		i;
	t_player 	*temp;
	t_player 	*ptr;

	i = 1;
	temp = player;
	while (i < num - 1)
		temp = temp->next;
	ptr = temp->next;
	temp->next = head;
	head->next = ptr;
}

void			valid_check(int fd, int argc, char **argv, t_player **player)
{
	int 		i;
	int 		num;
	t_player 	*head;
	t_player 	*buffer;

	i = 1;
	num = 0;
	while (argv[i])
	{
		head = init_player();
		check_magic(fd);
		check_name(fd, head);
		check_zeros(fd);
		length_exec_code(fd, head);
		champ_comment(fd, head);
		check_zeros(fd);
		check_champ_code(fd, head);
		if (ft_strcmp("-n", argv[i]) == 0)
		{
			if (is_numvalue(argv[++i]))
			{
				num = ft_atoi(&argv[i][0]);
				if (num < 0)
					write_error();
				put_box(num, *player, head);
			}
			else
				write_error();
		}
		else if (*player != NULL)
		{
			buffer = skip_box(*player);
			buffer->next = head;
		}
		else
			*player = head;
		i++;
	}
}
