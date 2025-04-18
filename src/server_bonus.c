/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:27:46 by egache            #+#    #+#             */
/*   Updated: 2025/04/08 16:28:07 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	del_int(void *content)
{
	free((int *)content);
}

int	list_char(int c)
{
	static t_list	*lst = NULL;
	t_list			*new_node;
	int				*c_ptr;
	t_list			*tmp;

	c_ptr = malloc(sizeof(int));
	if (!c_ptr)
		free(c_ptr);
	*c_ptr = c;
	new_node = ft_lstnew(c_ptr);
	ft_lstadd_back(&lst, new_node);
	if (c == '\0')
	{
		tmp = lst;
		while (tmp)
		{
			ft_printf("%c", *((int *)tmp->content));
			tmp = tmp->next;
		}
		ft_lstclear(&lst, del_int);
		return (1);
	}
	return (0);
}

int	stock_bits(int bit)
{
	static size_t	i = 0;
	int				j;
	int				c;
	int				ret;
	static int		bits[8];

	ret = 0;
	bits[i++] = bit;
	if (i == 8)
	{
		j = 0;
		c = 0;
		while (j < 8)
		{
			c = ((c << 1) | bits[j]);
			j++;
			i++;
		}
		if (list_char(c) == 1)
			ret = 1;
		i = 0;
	}
	return (ret);
}

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	int	ret;

	ret = 0;
	(void)context;
	know = 0;
	if (signum == SIGUSR1)
	{
		ret = stock_bits(1);
	}
	else if (signum == SIGUSR2)
	{
		ret = stock_bits(0);
	}
	if (ret == 0)
		kill(siginfo->si_pid, SIGUSR1);
	else
		kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	t_sigaction	action;

	ft_printf("PID : %d\n", getpid());
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
