/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:31 by egache            #+#    #+#             */
/*   Updated: 2025/03/13 18:28:06 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
// #include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct sigaction	t_sigaction;
volatile sig_atomic_t know = 1;

void	client_signal_handler(int signum)
{
	(void)signum;
	know = 0;

}

int	main(int argc, char **argv)
{
	char	*msg;
	char	*binstr;
	pid_t	pid;
	int		i;
	int		j;
	t_sigaction action;

	if (argc != 3)
		return (1);
	pid = atoi(argv[1]);
	msg = argv[2];
	binstr = msg;
	i = 0;
	j = 7;
	printf("PID : %d\n", getpid());
	action.sa_handler = client_signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	while (msg[i] != '\0' && msg)
	{
		while (j >= 0)
		{
			if (((msg[i] >> j) & 1) == 0)
			{
				printf("SIGUSR2 : %d\n", ((msg[i] >> j) & 1));
				kill(pid, SIGUSR2);
			}
			else if (((msg[i] >> j) & 1) == 1)
			{
				printf("SIGUSR1 : %d\n", ((msg[i] >> j) & 1));
				kill(pid, SIGUSR1);
			}
			while(know != 0)
				pause();
			know = 1;
			j--;
		}
		j = 7;
		i++;
	}
}
