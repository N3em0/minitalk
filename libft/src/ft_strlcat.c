/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:47:06 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:36:54 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j] && j < size)
		j++;
	if (j == size)
		return (j + ft_strlen((char *)src));
	while (src[i] && ((i + j + 1) < size))
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (j + ft_strlen((char *)src));
}
