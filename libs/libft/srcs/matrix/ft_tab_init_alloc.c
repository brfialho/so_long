/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_init_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:26:42 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 15:04:45 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_init_alloc(t_tab *tab, size_t rows, size_t cols, size_t e_size)
{
	size_t	i;

	tab->element_size = e_size;
	tab->cols = cols;
	tab->tab = ft_calloc(rows + 1, sizeof(void *));
	if (!tab->tab)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		tab->rows = i;
		tab->tab[i] = ft_calloc(cols + 1, e_size);
		if (!tab->tab[i])
			return (ft_tab_free_content(tab), NULL);
		i++;
	}
	tab->rows = i;
	return (tab);
}
