/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_init_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:27:14 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 15:04:46 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_init_empty(t_tab *tab, size_t rows, size_t cols, size_t e_size)
{
	tab->rows = rows;
	tab->cols = cols;
	tab->element_size = e_size;
	tab->tab = ft_calloc(rows + 1, sizeof(void *));
	if (!tab->tab)
		return (NULL);
	return (tab);
}
