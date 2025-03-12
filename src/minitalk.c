/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:28 by egache            #+#    #+#             */
/*   Updated: 2025/03/12 17:09:22 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	signal_handler(int signum)
{
	printf("Received SIGINT!\n", signum);
	exit(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	while (1)
	{
		sleep(5);
	}
	return (0);
}
