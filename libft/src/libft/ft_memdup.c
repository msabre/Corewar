/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:09:16 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/10 13:14:48 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		*ft_memdup(void *mem, int count)
{
	int		i;
	char	*new_mem;

	i = 0;
	new_mem = (char *)malloc(sizeof(char) * count);
	while (i < count)
	{
		new_mem[i] = ((char*)mem)[i];
		i++;
	}
	return (new_mem);
}