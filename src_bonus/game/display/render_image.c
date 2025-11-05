/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:39 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 20:32:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	render_image(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < (int)game->map.rows)
	{
		col = -1;
		while (++col < (int)game->map.cols)
		{
			if (((char **)game->map.tab)[row][col] == EXIT)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[E], col * SQUARE, row * SQUARE);
			if (((char **)game->map.tab)[row][col] == FLOOR)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[F], col * SQUARE, row * SQUARE);
			if (((char **)game->map.tab)[row][col] == WALL)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[W], col * SQUARE, row * SQUARE);
			if (((char **)game->map.tab)[row][col] == QUEST)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[Q], col * SQUARE, row * SQUARE);
			if (((char **)game->map.tab)[row][col] == ENEMY)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[M], col * SQUARE, row * SQUARE);
			if (((char **)game->map.tab)[row][col] == PLAYER)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[P], col * SQUARE, row * SQUARE);
		}
	}
}
