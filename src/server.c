/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:25 by egache            #+#    #+#             */
/*   Updated: 2025/03/13 20:21:24 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
// #include "get_next_line.h"
#define _POSIX_C_SOURCE 200809L
// #include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct sigaction	t_sigaction;
volatile sig_atomic_t know = 1;

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	know = 0;
	if (signum == SIGUSR1)
	{
		write(STDOUT_FILENO, "1", 2);
	}
	else if (signum == SIGUSR2)
		write(STDOUT_FILENO, "0", 2);
		//printf("PID CLIENT : %d\n", siginfo->si_pid);
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	t_sigaction	action;

	printf("PID : %d\n", getpid());
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		while (know != 0)
			pause();
		know = 1;
	}
	return (0);
}
