/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:58:12 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void			c_data(t_file *ssl, t_exec *com, t_label *list)
{
	label_change(list, &com);
	free_label(list);
	arg_add(&com);
	if ((ssl->text = open(ssl->f_name,
			O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		write_error("FILE DOESN'T CREAT");
	including_magic(ssl->text);
	including_size(ssl);
	line_to_write(&com, ssl);
}
