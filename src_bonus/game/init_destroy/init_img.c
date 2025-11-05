/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:21:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 20:31:50 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	init_basic_img(t_mlx *mlx);
static void	init_quest_img(t_mlx *mlx);
static void	int_monster_img(t_mlx *mlx);
static void	init_player_img(t_mlx *mlx);

int	init_img(t_mlx *mlx)
{
	int	i;

	init_basic_img(mlx);
	init_quest_img(mlx);
	int_monster_img(mlx);
	init_player_img(mlx);
	i = -1;
	while (++i < TEXTURES)
		if (!mlx->img[i])
			return (FALSE);
	return (TRUE);
}
static void	init_basic_img(t_mlx *mlx)
{
	mlx->img[E] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/exit.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[F] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/floor.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[W] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/wall.xpm", &mlx->img_width, &mlx->img_height);
}

static void	init_quest_img(t_mlx *mlx)
{
		mlx->img[Q] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/quest.xpm", &mlx->img_width, &mlx->img_height);
		mlx->img[Q_U] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/quest_up.xpm", &mlx->img_width, &mlx->img_height);
		mlx->img[Q_D] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/quest_down.xpm", &mlx->img_width, &mlx->img_height);
}

static void	int_monster_img(t_mlx *mlx)
{
	mlx->img[M] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/monster.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[M_L] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/monster_left.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[M_R] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/monster_right.xpm", &mlx->img_width, &mlx->img_height);
}

static void	init_player_img(t_mlx *mlx)
{
	mlx->img[P] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[P_L] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player_left.xpm", &mlx->img_width, &mlx->img_height);
	mlx->img[P_R] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player_right.xpm", &mlx->img_width, &mlx->img_height);
}

