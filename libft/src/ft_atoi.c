/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:09:37 by egache            #+#    #+#             */
/*   Updated: 2024/12/12 15:00:30 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > LLONG_MAX)
			return (ft_overflow(sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > LLONG_MAX)
		return (ft_overflow(sign));
	return ((int)result * sign);
}
/*
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", ft_atoi("9234567891234567891"));
	printf("%d\n", atoi("9234567891234567891"));
}*/
