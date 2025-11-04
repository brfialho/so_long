/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:57:34 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	map_init(t_tab *map, char **split)
{
	map->tab = (void **)split;
	map->element_size = sizeof(char);
	map->rows = ft_split_len(split);
	map->cols = ft_strlen(split[0]);
}
