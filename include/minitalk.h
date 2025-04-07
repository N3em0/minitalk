/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:37:39 by egache            #+#    #+#             */
/*   Updated: 2025/04/07 15:44:14 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct sigaction	t_sigaction;

volatile sig_atomic_t		know = 1;

// typedef struct s_lst
// {
// 	void					*content;
// 	struct s_lst			*next;
// }							t_lst;

#endif
