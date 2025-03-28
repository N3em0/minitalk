/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:48:41 by egache            #+#    #+#             */
/*   Updated: 2024/12/12 15:05:40 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		chr;

	i = 0;
	s = (const unsigned char *)str;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (chr == s[i])
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "Ploplaguilde";
	const char	chr = 'g';
	char		*ret;
	char		*ret2;

	ret = ft_memchr(str, chr, strlen(str));
	printf("Ma fonction / String apres |%c| - |%s|\n", chr, ret);
	ret2 = memchr(str, chr, strlen(str));
	printf("Original function / String apres |%c| - |%s|\n", chr, ret2);
	return (0);
}*/
