/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:30:26 by egache            #+#    #+#             */
/*   Updated: 2024/12/01 18:46:30 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long ptr)
{
	const char	*base;
	int			count;

	count = 0;
	base = "0123456789abcdef";
	if (ptr >= 16)
	{
		count += ft_printptr(ptr / 16);
	}
	count += ft_putchar(base[ptr % 16]);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	count += ft_printptr(ptr);
	return (count);
}
