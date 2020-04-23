/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 16:07:05 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

int				line_part(t_exec *com, unsigned char *s, int i, int n)
{
	long long	j;
	int			k;
	char		*a;
	int			ta;

	a = NULL;
	ta = com->ta1;
	ta = order_arg(com, &a, ta, n);
	j = ft_atoi(a);
	if (ta == 1)
		s[i++] = j;
	else if (ta == 2 && com->dir_size == 4)
		k = 3;
	else
		k = 1;
	if (ta != 1)
		while (k > -1)
			s[i++] = j >> (8 * k--);
	return (i);
}
