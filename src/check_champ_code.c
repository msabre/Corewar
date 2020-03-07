/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champ_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:01:43 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/07 14:30:43 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void    check_champ_code(int fd, t_player *player)
{
    int             text;
    unsigned char   buffer[player->len_exec + 1];
    size_t          i;

    if ((text = read(fd, &buffer, player->len_exec)) == -1)
        write_error("ERROR WITH THE READING A FILE");
    if (text < player->len_exec)
        write_error("INVALID SIZE");
    if(!(player->exe_code = (char *)malloc(sizeof(char *) * player->len_exec)))
        exit(0);
    i = 0;
    while(i < player->len_exec)
    {
		player->exe_code[i] <<= 8;
		player->exe_code[i] |= buffer[i];
        i++;
    }
    printf("%s", player->exe_code);
}
