/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:12:59 by egache            #+#    #+#             */
/*   Updated: 2025/02/14 17:02:20 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_printhex(unsigned int nbr, int c);
int		ft_printstr(char *str);
int		ft_printint(int nbr);
int		ft_printuint(unsigned int nbr);
int		ft_putptr(unsigned long ptr);
int		ft_printptr(unsigned long ptr);
int		ft_putchar(char c);

#endif
