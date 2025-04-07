/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:41:25 by egache            #+#    #+#             */
/*   Updated: 2025/04/07 16:10:55 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	list_char(int c)
{
	static t_list	*lst = NULL;
	t_list			*new_node;
	int				*c_ptr;
	t_list			*tmp;

	c_ptr = malloc(sizeof(int));
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
		ft_lstclear(lst, );
	}
	//printf("\nNouveau caractère: %c\n", c);
	// while (tmp)
	// {
	// 	printf("%c -> ", *((int *)tmp->content));
	// 	tmp = tmp->next;
	// }
	//printf("NULL\n");
}

void	stock_bits(int bit)
{
	static size_t	i = 0;
	int				j;
	int				c;
	static int		bits[8];

	bits[i++] = bit;
	//printf("\nbits[i] = %d\n", bits[i]);
	if (i == 8)
	{
		j = 0;
		c = 0;
		i = 0;
		while (j < 8)
		{
			c = ((c << 1) | bits[j]);
			//printf("\nbits[j] = %d", bits[j]);
			//printf(" bits[i] = %d", bits[i]);
			j++;
			i++;
		}
		list_char(c);
		// c_ptr = malloc(sizeof(int));
		// *c_ptr = c;
		// new_node = ft_lstnew(c_ptr);
		// ft_lstadd_back(&lst, new_node);
		// printf("\nNouveau caractère: %c\n", c);
		// tmp = lst;
		// while (tmp)
		// {
		// 	printf("%c -> ", *((int *)tmp->content));
		// 	tmp = tmp->next;
		// }
		// printf("NULL\n");
		// printf("\nchar = %c & int value = %d\n", c, c);
		// write(STDOUT_FILENO, &c, 2);
		i = 0;
	}
}

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	know = 0;
	if (signum == SIGUSR1)
	{
		stock_bits(1);
	}
	else if (signum == SIGUSR2)
	{
		stock_bits(0);
	}
	// printf("PID CLIENT : %d\n", siginfo->si_pid);
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

// list chainee : alloue un node par bit a chaque signal recu
// compte jusqu'a 8 : puis bitshift/wise	a l'envers
// malloc ma string finale a (le nombre de noeud / 8) + 1
// et put la valeur ascii dans chaque case de la string str[i] =

// QUAND SIGNAL RECU
// stocker 8 bits dans un tab[8]
// une fois 8 bit -> convertir en char
// creer un noeud avec comme content content char c
// repeter tant que signal recu
