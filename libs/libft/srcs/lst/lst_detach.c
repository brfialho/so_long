/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_detach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:56:50 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_detach(t_list **head, t_list *node)
{
	t_list	*lst;

	if (*head == node)
	{
		*head = (*head)->next;
		node->next = NULL;
		return (node);
	}
	lst = *head;
	while (lst)
	{
		if (lst->next == node)
		{
			lst->next = node->next;
			node->next = NULL;
			return (node);
		}
		lst = lst->next;
	}
	return (NULL);
}
