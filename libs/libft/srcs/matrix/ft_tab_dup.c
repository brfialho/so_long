/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:49:06 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 13:45:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_dup(t_tab tab)
{
	t_tab	*new;
	size_t	i;

	new = ft_calloc(1, sizeof(t_tab));
	if (!new)
		return (NULL);
	if (!ft_tab_init_alloc(new, tab.rows, tab.cols, tab.element_size))
		return (free(new), NULL);
	i = 0;
	while (i < new->rows)
	{
		ft_memmove(new->tab[i], tab.tab[i], new->cols * new->element_size);
		i++;
	}
	return (new);
}
