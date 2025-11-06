/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:39 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:13:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	render_enviroment(t_game *game, char tile, int col, int row);
static void	render_monster(t_game *game, char tile, int col, int row);
static void	render_player(t_game *game, char tile, int col, int row);
static void	render_quest(t_game *game, int col, int row);

void	render_image(t_game *game)
{
	int		row;
	int		col;
	char	tile;

	row = -1;
	while (++row < (int)game->map.rows)
	{
		col = -1;
		while (++col < (int)game->map.cols)
		{
			tile = ((char **)game->map.tab)[row][col];
			if (tile == EXIT || tile == FLOOR || tile == WALL)
				render_enviroment(game, tile, col * SQUARE, row * SQUARE);
			if (tile == QUEST)
				render_quest(game, col * SQUARE, row * SQUARE);
			if (ft_strchr(MONSTER_SET, tile))
				render_monster(game, tile, col * SQUARE, row * SQUARE);
			if (ft_strchr(PLAYER_SET, tile))
				render_player(game, tile, col * SQUARE, row * SQUARE);
			display_moves(game);
		}
	}
}
static void	render_enviroment(t_game *game, char tile, int col, int row)
{
	if (tile == EXIT)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[E], col, row);
	if (tile == FLOOR)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[F], col, row);
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[W], col, row);
}

static void	render_quest(t_game *game, int col, int row)
{
	if (game->frame > FRAME_MAX / 4 && game->frame < FRAME_MAX / 2)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[Q_D], col, row);
	else if (game->frame > (FRAME_MAX / 4) * 3  && game->frame < FRAME_MAX)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[Q_U], col, row);
	else
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[Q], col, row);
}

static void	render_monster(t_game *game, char tile, int col, int row)
{
	if (tile == MONSTER)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[M], col, row);
	if (tile == MONSTER_LEFT)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[M_L], col, row);
	if (tile == MONSTER_RIGHT)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[M_R], col, row);
}

static void	render_player(t_game *game, char tile, int col, int row)
{
	if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[P], col, row);
	if (tile == PLAYER_LEFT)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[P_L], col, row);
	if (tile == PLAYER_RIGHT)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[P_R], col, row);
}