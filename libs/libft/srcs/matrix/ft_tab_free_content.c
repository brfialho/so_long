/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_free_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:25:35 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/22 14:25:53 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_free_content(t_tab *tab)
{
	while (tab->rows)
		free(tab->tab[--tab->rows]);
	free(tab->tab);
	tab->tab = NULL;
}
