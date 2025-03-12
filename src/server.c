/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:25 by egache            #+#    #+#             */
/*   Updated: 2025/03/12 19:24:59 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
// #include "ft_printf.h"
// #include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

typedef struct sigaction t_sigaction;

void	signal_handler(int signum)
{
	if (signum == 10)
		write(STDOUT_FILENO, "SIGNAL received\n", 16);
	else if (signum == SIGUSR2)
		write(STDOUT_FILENO, "cacaboudin\n", 11);
}

int	main(void)
{
	t_sigaction	action;

	printf("PID : %d\n", getpid());
	sigemptyset(&action.sa_mask);
	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		// Do some work
	}
	return (0);
}

//Powered by OpenAI
