/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_opera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:28:16 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

t_exec	*take_opera(t_file *ssl, char *line, int i, t_exec *com)
{
	com = init_exec();
	com->line_byte = ssl->line_byte;
	compare(ssl, line, i, com);
	ssl->line_byte = ssl->line_byte + com->n_bytes;
	return (com);
}
