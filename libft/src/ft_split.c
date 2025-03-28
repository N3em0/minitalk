/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:46:00 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:36:39 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char sep)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i] != '\0')
			count++;
		while (!(str[i] == sep) && str[i])
			i++;
	}
	return (count);
}

static char	*putword(const char *str, int pos, char sep)
{
	int		i;
	int		j;
	int		k;
	int		wordlen;
	char	*word;

	i = pos;
	k = i;
	j = 0;
	while (!(str[k] == sep) && str[k])
		k++;
	wordlen = k - i;
	word = (char *)malloc((wordlen + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (str[i] && !(str[i] == sep))
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	free_split(char **split, int word_count)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (i < word_count)
	{
		if (split[i])
		{
			free(split[i]);
			split[i] = NULL;
		}
		i++;
	}
	free(split);
}

static char	**putstrs(const char *str, int sep, char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] == sep) && str[i])
			i++;
		if (!(str[i] == sep) && str[i])
		{
			strs[j] = putword(str, i, sep);
			if (!strs[j++])
			{
				free_split(strs, j);
				return (NULL);
			}
		}
		while (!(str[i] == sep) && str[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(const char *str, char sep)
{
	char	**strs;

	strs = (char **)malloc((count_word(str, sep) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (putstrs(str, sep, strs));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		i;
// 	char	**split;

// 	split = ft_split("hello! a a a", ' ');
// 	i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }
