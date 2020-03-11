/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:17:26 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/11 14:23:45 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>

int					main()
{
	int				i = 0;
	int				size = 4;
	int				num = -1;
	unsigned char	c;

	while (size > 0)
	{
		c = (uint8_t)((num >> i) & 0xFF);
		i += 8;
		size--;
	}
	return (0);
}