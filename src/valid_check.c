/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:23:51 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/06 20:09:32 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		put_box(int num, t_player *player, t_player *head)
{
	int 		i;
	t_player 	*temp;
	t_player 	*ptr;

	i = 1;
	temp = player;
	while (i++ < num - 1)
	{
		temp->num = i;
		temp = temp->next;
	}
	ptr = temp->next;
	temp->next = head;
	head->next = ptr;
	while (ptr->next != NULL)
	{
		ptr->num = i;
		ptr = ptr->next;
	}
}

void			valid_check(int fd, char *argv, t_general *all)
{
	t_player 	*head;
	t_player 	*buffer;

	head = init_player();
	check_magic(fd);
	check_name(fd, head);
	check_zeros(fd);
	length_exec_code(fd, head);
	champ_comment(fd, head);
	check_zeros(fd);
	check_champ_code(fd, head);
	if (all->flag_n != 0)
		put_box(all->flag_n, all->players, head);
	else if (all->players != NULL)
	{
		buffer = skip_box(all->players);
		buffer->next = head;
	}
	else
		all->players = head;
}
