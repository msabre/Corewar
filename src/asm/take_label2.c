/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_label2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:15 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void		take_label2(char *line, t_file *ssl, int i, t_label **list)
{
	char	*name;

	if (!(name = ft_strsub(line, ssl->a, i)))
		write_error("ERROR_STR_LABEL");
	add_label(list, cnl(name, ssl->line_byte));
	ssl->a = ssl->a + i + 1;
}
