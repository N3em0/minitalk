/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:29:10 by egache            #+#    #+#             */
/*   Updated: 2024/12/18 14:36:08 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int nbr)
{
	int		i;
	char	*str;
	int		count;

	count = 0;
	i = 0;
	str = ft_itoa(nbr);
	while (str && str[i])
		count += ft_putchar(str[i++]);
	free(str);
	return (count);
}
