/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:05:55 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:36:03 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		llen;
	t_list	*current;

	llen = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		llen++;
	}
	return (llen);
}
