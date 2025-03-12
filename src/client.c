/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:31 by egache            #+#    #+#             */
/*   Updated: 2025/03/12 19:36:51 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	signal_handler(int signum)
// {
// 	int bit;

// 	if (signum == SIGUSR1)
// 		bit = 1;
// 	else if (signum == SIGUSR2)
// 		bit = 0;
// }

int	main(int argc, char **argv)
{
	char	*msg;
	pid_t	pid;

	pid = atoi(argv[1]);
	msg = argv[2];
	if (msg[0] == '0')
		kill(pid, SIGUSR2);
	if (msg[0] == '1')
		kill(pid, SIGUSR1);
	// signal(SIGUSR1, signal_handler);
	// signal(SIGUSR2, signal_handler);
}
