/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:28:11 by egache            #+#    #+#             */
/*   Updated: 2025/04/24 23:13:58 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_know = 1;

void	client_signal_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message has been received\n");
	g_know = 0;
}

void	send_eos(pid_t pid, char c)
{
	int	j;

	j = 7;
	if (c == '\0')
	{
		while (j >= 0)
		{
			kill(pid, SIGUSR2);
			while (g_know != 0)
				pause();
			g_know = 1;
			j--;
		}
	}
}

void	send_message(pid_t pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	j = 7;
	while (msg[i] != '\0' && msg)
	{
		while (j >= 0)
		{
			if (((msg[i] >> j) & 1) == 0)
				kill(pid, SIGUSR2);
			else if (((msg[i] >> j) & 1) == 1)
				kill(pid, SIGUSR1);
			j--;
			while (g_know != 0)
				pause();
			g_know = 1;
		}
		j = 7;
		i++;
	}
	send_eos(pid, msg[i]);
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	t_sigaction	action;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putendl_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	action.sa_handler = client_signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_message(pid, argv[2]);
	return (0);
}
