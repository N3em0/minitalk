/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:45:32 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:36:21 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;

	s = (char *)str;
	while (n > 0)
	{
		s[n - 1] = c;
		n--;
	}
	return (str);
}
/*
int	main(void)
{
	char buffer[50];
	ft_memset(buffer, '*', sizeof(buffer) - 1);
	buffer[49] = '\0';

	printf("Buffer %s\n", buffer);
	printf("Buffer Size %lu\n", sizeof(buffer));
	return (0);
}*/
