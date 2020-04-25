/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:47:40 by msabre            #+#    #+#             */
/*   Updated: 2020/04/25 11:55:24 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strndup(const char *str, int start, int end)
{
	int		length;
	char	*ptr;

	length = end - start;
	ptr = (char*)malloc(sizeof(char) * (length + 2));
	if (!ptr)
		return (NULL);
	while (start <= end && str[start + 1] != '\0')
	{
		ptr[start] = str[start];
		start++;
	}
	ptr[start] = '\0';
	return (ptr);
}
