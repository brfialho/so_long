/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:41:40 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_del_all(t_list **head, void (*del)(void*))
{
	t_list	*lst;
	t_list	*node;

	lst = *head;
	while (lst)
	{
		node = lst;
		lst = lst->next;
		if (del)
			del(node->content);
		free(node);
	}
	*head = 0;
}

// void ft_delete(void	*v)
// {
// 	free(v);
// }
// #include <stdio.h>
// int	main(void)
// {
// 	// t_list a;
// 	// t_list b;
// 	// t_list c;
// 	// t_list *lst;

// 	// c.next = 0;
// 	// b.next = &c;
// 	// a.next = &b;
// 	// lst = &a;

// 	t_list	*a = malloc(sizeof(t_list));
// 	t_list *b   = malloc(sizeof(t_list));
// 	t_list *c   = malloc(sizeof(t_list));
// 	t_list **lst = malloc(sizeof(t_list *));

// 	*lst = a;
// 	a->next = b;
// 	b->next = c;
// 	c->next = 0;

// 	// printf("%p\n", a);
// 	// printf("%p\n", b);
// 	// printf("%p\n", c);
// 	lst_del_all(lst, &ft_delete);
// 	// printf("%p\n", a);
// 	// printf("%p\n", b);
// 	// printf("%p\n", c);

// 	// int	*i = malloc (4);
// 	// *i = 4;
// 	// printf("%p %d\n", i, *i);
// 	// free(i);
// 	// printf("%p %d\n", i, *i);

// 	free(lst);
// }