/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:06 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:36:59 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen((char *)src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1 && i < srcsize)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[5] = "plop";
	char	dest[3] = "";
	ft_strlcpy(dest, src, 3);
	printf("%s\n", dest);
	printf("%s", src);
}*/
