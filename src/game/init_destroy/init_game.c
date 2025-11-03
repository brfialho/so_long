/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:25:47 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 18:25:58 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_game(t_game *game)
{
	game->moves = 0;
	game->mlx.height = (int)game->map.rows * SQUARE;
	game->mlx.width = (int)game->map.cols * SQUARE;
	ft_bzero(game->mlx.key_is_pressed, sizeof(game->mlx.key_is_pressed));
	if (!init_mlx_display(&game->mlx))
		destroy_game(game);
}
