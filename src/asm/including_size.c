/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   including_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 09:16:12 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

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
