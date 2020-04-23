/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   including_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 09:16:12 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void				including_size(t_file *ssl)
{
	int				i;
	unsigned char	buffer[4];

	i = 0;
	while (i < 4)
	{
		buffer[i] = ssl->line_byte >> (8 * (3 - i));
		i++;
	}
	write(ssl->text, ssl->name, PROG_NAME_LENGTH);
	write(ssl->text, ssl->zero, T_IND);
	write(ssl->text, buffer, 4);
	write(ssl->text, ssl->comment, COMMENT_LENGTH);
	write(ssl->text, ssl->zero, T_IND);
}
