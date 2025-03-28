/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:11:33 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:35:18 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*str;

	if (size != 0 && nitems > SIZE_MAX / size)
		return (NULL);
	str = malloc(nitems * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nitems * size);
	return (str);
}
