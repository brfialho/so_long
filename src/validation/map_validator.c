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

void	map_validator(t_game *game)
{

	check_size(&game->map);
	check_borders_row(&game->map);
	check_borders_col(&game->map);
	check_chars(&game->map, &game->obj);
	check_valid_path(&game->map, game->obj, &game->player, &game->exit);
}