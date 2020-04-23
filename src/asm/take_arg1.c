/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:06:48 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	take_arg1(char *line, t_file *ssl, t_exec *com)
{
	skip_probel(ssl, line);
	if (line[ssl->a] == 'r')
		take_arg1_r(line, ssl, com, 0);
	else if (line[ssl->a] == '%' && line[ssl->a + 1] && line[ssl->a + 1] != ':')
		take_arg1_pr(line, ssl, com, 1);
	else if (line[ssl->a + 1] && line[ssl->a + 1] == ':')
		take_arg1_d(line, ssl, com, 2);
	else if (ft_isdigit(line[ssl->a]))
		take_arg1_n(line, ssl, com, 1);
	else if (line[ssl->a] == '-')
		take_arg1_neg(line, ssl, com, 1);
	else if (line[ssl->a] == ':')
		take_arg1_dv(line, ssl, com, 1);
	else
		write_error("WRONG_ARGUMENT");
}
