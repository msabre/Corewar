/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 11:33:18 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void	no_comment(t_file *ssl, const char *li)
{
	if (li[ssl->a] == '#' || li[ssl->a] == ';')
		while (li[ssl->a] && li[ssl->a] != '\n')
			ssl->a++;
}
