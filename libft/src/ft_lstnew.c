/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:49 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 16:36:01 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nextnode;

	nextnode = malloc(sizeof(t_list));
	if (!nextnode)
		return (nextnode);
	nextnode->content = content;
	nextnode->next = NULL;
	return (nextnode);
}
