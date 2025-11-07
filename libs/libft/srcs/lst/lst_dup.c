/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:58:04 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_dup(t_list *head, void (*del)(void *))
{
	t_list	*lst;
	t_list	*new;
	t_list	*node;

	lst = head;
	new = lst_new_node(lst->content);
	if (!new)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		node = lst_new_node(lst->content);
		if (!node)
			return (lst_del_all(&new, del), NULL);
		lst_add_end(&new, node);
		lst = lst->next;
	}
	return (new);
}
