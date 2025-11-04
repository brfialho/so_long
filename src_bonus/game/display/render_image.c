/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:39 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	render_image(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < (int)game->map.rows)
	{
		col = -1;
		while (++col < (int)game->map.cols)
		{
			if (((char **)game->map.tab)[row][col] == PLAYER)
				draw_square(game->mlx, row, col, get_rgb(255, 0, 0));
			if (((char **)game->map.tab)[row][col] == QUEST)
				draw_square(game->mlx, row, col, get_rgb(255, 255, 0));
			if (((char **)game->map.tab)[row][col] == FLOOR)
				draw_square(game->mlx, row, col, get_rgb(128, 128, 128));
			if (((char **)game->map.tab)[row][col] == WALL)
				draw_square(game->mlx, row, col, get_rgb(0, 0, 0));
			if (((char **)game->map.tab)[row][col] == EXIT)
				draw_square(game->mlx, row, col, get_rgb(255, 255, 255));
		}
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, \
							game->mlx.win_ptr, \
							game->mlx.img.img_ptr, 0, 0);
	return (0);
}
