/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:06:02 by almazg            #+#    #+#             */
/*   Updated: 2020/04/23 21:07:05 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	take_arg3(char *line, t_file *ssl, t_exec *com)
{
	skip_probel(ssl, line);
	if (line[ssl->a] == 'r')
		take_arg3_r(line, ssl, com, 0);
	else if (line[ssl->a] == '%' && line[ssl->a + 1] && line[ssl->a + 1] != ':')
		take_arg3_pr(line, ssl, com, 1);
	else if (line[ssl->a + 1] && line[ssl->a + 1] == ':')
		take_arg3_d(line, ssl, com, 2);
	else if (ft_isdigit(line[ssl->a]))
		take_arg3_n(line, ssl, com, 1);
	else if (line[ssl->a] == '-')
		take_arg3_neg(line, ssl, com, 1);
	else if (line[ssl->a] == ':')
		take_arg3_dv(line, ssl, com, 1);
	else
		write_error("WRONG_ARGUMENT");
}
