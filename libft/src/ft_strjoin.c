/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:46 by egache            #+#    #+#             */
/*   Updated: 2025/03/14 14:33:46 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlentotal(char *s1, char *s2)
{
	int	lentotal;

	lentotal = ft_strlen(s1) + ft_strlen(s2) + 1;
	return (lentotal);
}

static char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		lentotal;

	if (s1 && s2)
	{
		lentotal = ft_strlentotal((char *)s1, (char *)s2);
		join = ft_calloc(1, lentotal);
		if (!join)
			return (NULL);
	}
	else
		return (NULL);
	ft_strcat(join, (char *)s1);
	ft_strcat(join, (char *)s2);
	return (join);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*join;
	char	*strs1;
	char	*strs2;

	strs1 = "ABCD";
	strs2 = "EHOGEG";
	join = ft_strjoin(strs1, strs2);
	printf("la string finale : %s\n", join);
}
*/
