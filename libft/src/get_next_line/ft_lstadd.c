/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:21:14 by msabre            #+#    #+#             */
/*   Updated: 2020/03/23 12:51:34 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

void			ft_lstadd(t_gnlist **alst, t_gnlist *new)
{
	t_gnlist	*ptr;

	ptr = *alst;
	if (!ptr)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
	}
}
