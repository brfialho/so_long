/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:39 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 20:51:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void display_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	if (!moves)
		destroy_game(game);
	game->moves_str = ft_strjoin("Movement Counter: ", moves);
	free(moves);
	if (!game->moves_str)
		destroy_game(game);
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, SQUARE, SQUARE / 2, get_rgb(0, 255, 0), game->moves_str);
	free(game->moves_str);
	game->moves_str = NULL;
}


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
			if (((char **)game->map.tab)[row][col] == PLAYER)
				draw_square(game->mlx, row, col, get_rgb(255, 0, 0));
			if (((char **)game->map.tab)[row][col] == ENEMY)
				draw_square(game->mlx, row, col, get_rgb(75, 0, 130));
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
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
							game->mlx.img.img_ptr, 0, 0);
	display_moves(game);
}
