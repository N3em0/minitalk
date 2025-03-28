/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:07:14 by egache            #+#    #+#             */
/*   Updated: 2024/12/10 15:25:33 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (!(unsigned char)c && str[i] == '\0')
		return ((char *)str + i);
	return (NULL);
}
// int	main(void)
// {
// 	const char	str[] = "Salutlre9geraguilde";
// 	const char	chr = '9';
// 	char		*ret;
// 	char		*ret2;

// 	ret = ft_strchr(str, chr);
// 	printf("Ma fonction / String apres %c : %s\n", chr, ret);
// 	ret2 = strchr(str, chr);
// 	printf("Original function / String after %c : %s\n", chr, ret2);
// 	return (0);
// }
