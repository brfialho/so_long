/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:54:04 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_bubble_sort(t_list *head, int (*cmp)(void *, void *))
{
	void	*tmp;
	int		len;
	t_list	*i;

	len = lst_size(head);
	while (len--)
	{
		i = head;
		while (i->next)
		{
			if (cmp(i->content, i->next->content))
			{
				tmp = i->content;
				i->content = i->next->content;
				i->next->content = tmp;
			}
			i = i->next;
		}
	}
}
