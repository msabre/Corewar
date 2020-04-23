/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:09:16 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 23:08:48 by msabre           ###   ########.fr       */
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
