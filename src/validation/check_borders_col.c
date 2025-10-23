/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:11:22 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:12:55 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_borders_col(t_tab *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < map->rows)
		if (((char **)map->tab)[row++][col] != '1')
			validator_error_handler(map);
	row = 0;
	col = map->cols - 1;
	while (row < map->rows)
		if (((char **)map->tab)[row++][col] != '1')
			validator_error_handler(map);
}
