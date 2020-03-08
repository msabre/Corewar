/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:25:29 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/08 10:52:55 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_player	*init_player()
{
	t_player *ssl;

	if (!(ssl = (t_player *)ft_memalloc(sizeof(t_player))))
		exit (0);
	return (ssl);
}