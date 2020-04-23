/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_limit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:48:51 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

int	is_limit(int c)
{
	return (c == '\0' || c == '\n' || is_whitespace(c) || c == '.'
			|| c == '\"' || c == '%' || c == ',' || c == '#' || c == ';');
}
