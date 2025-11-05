/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:25:47 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 18:40:57 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	find_monsters(t_game *game);

int	init_textures(t_mlx *mlx)
{
	int	i;

	mlx->img[E] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/exit.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[F] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/floor.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[W] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/wall.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[Q] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/quest.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[M_D] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/monster_down.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[P_D] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player_down.xpm", &mlx->img_width, &mlx->img_height);
	
	i = -1;
	while (++i < TEXTURES)
		if (!mlx->img[i])
			return (FALSE);
	return (TRUE);
}

void	init_game(t_game *game)
{
	ft_bzero(&game->mlx, sizeof(game->mlx));
	game->moves = 0;
	game->mlx.total_height = (int)game->map.rows * SQUARE;
	game->mlx.total_width = (int)game->map.cols * SQUARE;
	if (!init_mlx_display(&game->mlx))
		destroy_game(game);
	if (!init_textures(&game->mlx))
		destroy_game(game);
	game->monster = ft_calloc(game->obj.x_count, sizeof(t_monster));
	if (!game->monster)
		destroy_game(game);
	find_monsters(game);
}

static void	find_monsters(t_game *game)
{
	int	i;
	int	j;
	int	m;

	m = 0;
	i = -1;
	while (++i < (int)game->map.rows)
	{
		j = -1;
		while (++j < (int)game->map.cols)
			if (((char **)game->map.tab)[i][j] == ENEMY)
				game->monster[m++].pos = (t_pos){i, j};
	}
}
