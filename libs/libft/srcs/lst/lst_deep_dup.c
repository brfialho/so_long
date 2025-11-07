/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_deep_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:00:18 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_deep_dup(t_list *head, void *(*copy)(void *), void (*del)(void *))
{
	t_list	*lst;
	t_list	*new;
	t_list	*node;
	void	*content;

	lst = head;
	content = copy(lst->content);
	if (!content)
		return (NULL);
	new = lst_new_node(content);
	if (!new)
		return (del(content), NULL);
	lst = lst->next;
	while (lst)
	{
		content = copy(lst->content);
		if (!content)
			return (lst_del_all(&new, del), NULL);
		node = lst_new_node(content);
		if (!node)
			return (del(content), lst_del_all(&new, del), NULL);
		lst_add_end(&new, node);
		lst = lst->next;
	}
	return (new);
}
