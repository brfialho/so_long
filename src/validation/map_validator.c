/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:18:37 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:18:59 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	map_validator(t_tab *map)
{
	t_char_counter	counter;

	check_size(map);
	check_borders_row(map);
	check_borders_col(map);
	check_chars(map, &counter);
	check_valid_path(map, counter);
}