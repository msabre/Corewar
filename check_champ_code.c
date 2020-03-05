/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champ_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:01:43 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/05 16:28:31 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void    check_champ_code(int fd, t_player *player)
{
    int             text;
    unsigned char   buffer[player->len_exec + 1];
    size_t          i;

    if ((text = read(fd, &buffer, player->len_exec)) == -1)
        write_error();
    if (text < player->len_exec)
        write_error();
    if(!(player->exe_code = (char *)malloc(sizeof(char *) * player->len_exec)))
        exit(0);
    i = 0;
    while(i < player->len_exec)
    {
    	if (buffer[i] != '\0') {
			player->exe_code[i] <<= 8;
			player->exe_code[i] |= buffer[i];
		}
    	else
			player->exe_code[i] = 48;
    	i++;

    }
    printf("%s", player->exe_code);
}
