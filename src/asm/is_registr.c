/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_registr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:57:00 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

int	is_registr(const char *a)
{
	int	i;

	i = 0;
	if (ft_strlen(a) >= 2 && ft_strlen(a) <= 3 && a[i] == 'r')
	{
		i++;
		while (ft_isdigit(a[i]))
			i++;
		return (!a[i] && ft_atoi(&a[1]) > 0);
	}
	return (0);
}
