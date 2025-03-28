/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:51:48 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:37:20 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i] - c);
}

static int	ft_start(const char *s1, const char *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strcmp(set, s1[start]) == 0)
		start++;
	return (start);
}

static int	ft_end(const char *s1, const char *set, int start)
{
	int	len;

	len = ft_strlen((char *)s1);
	while (len > start && ft_strcmp(set, s1[len - 1]) == 0)
		len--;
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set, start);
	str = ft_calloc(1, (end - start) + 1);
	if (!str)
		return (NULL);
	while (i + start < end)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int	main(void)
// {
// 	const char	*s1 = "    plop la guilde    ;  ";
// 	const char	*set = " ";

// 	printf("trimmed : %s", ft_strtrim(s1, set));
// }
