/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_int_mass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:52:33 by msabre            #+#    #+#             */
/*   Updated: 2019/10/30 23:01:29 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		size_int_mass(int *a)
{
	int	i;

	i = 0;
	while (a[i] >= 0)
		i++;
	return (i);
}