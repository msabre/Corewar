/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skolkovo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:09:33 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		skolkovo(char *line, t_file *ssl)
{
	t_exec	*head;

	name_comment(line, ssl);
	head = connecting_people(line, ssl);
	close(ssl->text);
	write(1, "\n", 1);
	ft_putstr("Writing bytecode to ");
	ft_putendl(ssl->f_name);
	free_exec(head);
}
