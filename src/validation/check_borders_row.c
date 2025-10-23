/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:10:30 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:11:08 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_borders_row(t_tab *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (col < map->cols)
		if (((char **)map->tab)[row][col++] != '1')
			validator_error_handler(map);
	row = map->rows - 1;
	col = 0;
	while (col < map->cols)
		if (((char **)map->tab)[row][col++] != '1')
			validator_error_handler(map);
}
