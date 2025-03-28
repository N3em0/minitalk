/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:48:17 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:38:20 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (str[i + j] == to_find[j] && (i + j) < n)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
