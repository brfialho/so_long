/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_init_fields.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:14:15 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/22 18:24:08 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_init_fields(t_tab *tab, size_t rows, size_t cols, size_t e_size)
{
	tab->rows = rows;
	tab->cols = cols;
	tab->element_size = e_size;
	tab->tab = NULL;
	return (tab);
}
