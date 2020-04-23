/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kod_type_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:46:05 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 08:57:40 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/andrejskobelev/c_files/Corewar/includes/asm.h"

void		kod_type_arg(t_exec **com)
{
	char	*temp;
	t_exec	*c;
	int		b;
	int		s;

	c = *com;
	c->kta = ft_strnew(1);
	add_kta(&c, 1);
	add_kta(&c, 2);
	add_kta(&c, 3);
	temp = ft_strjoin(c->kta, "00");
	ft_strdel(&(c->kta));
	b = 0;
	s = 0;
	while (temp[b])
		s = s * 2 + (temp[b++] - '0');
	ft_strdel(&temp);
	c->ta = s;
}
