/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:37:39 by egache            #+#    #+#             */
/*   Updated: 2025/04/25 16:09:20 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct sigaction	t_sigaction;

void						del_int(void *content);

void						write_message(t_list *lst);
void						list_char(int c);
void						stock_bits(int bit);
void						signal_handler(int signum, siginfo_t *siginfo,
								void *context);

void						client_signal_handler(int signum);
void						send_eos(pid_t pid, char c);
void						send_message(pid_t pid, char *msg);

#endif
