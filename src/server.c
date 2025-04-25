/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:25 by egache            #+#    #+#             */
/*   Updated: 2025/04/25 17:39:19 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_know = 1;

void	write_message(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%c", *((int *)tmp->content));
		tmp = tmp->next;
	}
	ft_lstclear(&tmp, del_int);
}

void	list_char(int c)
{
	static t_list	*lst = NULL;
	t_list			*new_node;
	int				*c_ptr;

	c_ptr = malloc(sizeof(int));
	if (c_ptr == NULL)
		exit(EXIT_FAILURE);
	*c_ptr = c;
	new_node = ft_lstnew(c_ptr);
	if (new_node == NULL)
	{
		ft_lstclear(&lst, del_int);
		free(c_ptr);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(&lst, new_node);
	if (c == '\0')
	{
		write_message(lst);
		write(1, "\n", 1);
		ft_lstclear(&lst, del_int);
	}
}

void	stock_bits(int bit)
{
	static size_t	i = 0;
	int				j;
	int				c;
	static int		bits[8];

	bits[i] = bit;
	i++;
	if (i == 8)
	{
		j = 0;
		c = 0;
		while (j < 8)
		{
			c = ((c << 1) | bits[j]);
			j++;
		}
		list_char(c);
		i = 0;
	}
}

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	g_know = 0;
	if (signum == SIGUSR1)
	{
		stock_bits(1);
	}
	else if (signum == SIGUSR2)
	{
		stock_bits(0);
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	t_sigaction	action;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_printf("PID : %d\n", getpid());
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		while (g_know != 0)
			pause();
		g_know = 1;
	}
	return (0);
}
