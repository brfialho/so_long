/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:39 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 16:24:26 by brfialho         ###   ########.fr       */
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
			if (((char **)game->map.tab)[row][col] == ENEMY)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[0], col * SQUARE, row * SQUARE);
		}
	}
}
