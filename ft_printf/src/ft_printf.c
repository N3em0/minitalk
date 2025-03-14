/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:28:47 by egache            #+#    #+#             */
/*   Updated: 2024/12/18 14:58:13 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_spectype(char c, va_list arg, int count)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 's')
		return (ft_printstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(arg, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_printint(va_arg(arg, int)));
	if (c == 'u')
		return (ft_printuint(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(arg, unsigned int), c));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			count += ft_spectype(str[++i], arg, count);
			i++;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(arg);
	return (count);
}
