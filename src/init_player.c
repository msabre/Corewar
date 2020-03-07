/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:25:29 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 16:28:32 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_player	*init_player()
{
	t_player *ssl;

	if (!(ssl = (t_player *)malloc(sizeof(t_player))))
		exit (0);
	ssl->num = 0;
	ssl->name = NULL;
	ssl->len_exec = 0;
	ssl->comment = NULL;
	ssl->exe_code = NULL;
	ssl->code_size = 0;
	return (ssl);
}