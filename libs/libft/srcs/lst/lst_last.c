/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:56:26 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_last(t_list *head)
{
	while (head->next)
		head = head->next;
	return (head);
}
// #include <stdio.h>
// int	main(void)
// {
// 	t_list a;
// 	t_list b;
// 	t_list c;
// 	t_list *lst;

// 	c.next = 0;
// 	b.next = &c;
// 	a.next = &b;
// 	lst = &a;
// 	printf("%p %p\n", &c, lst_last(lst));
// }