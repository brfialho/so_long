/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/22 13:00:16 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	destroy_game(t_game *game)
{
	destroy_img(&game->mlx);
	destroy_mlx(&game->mlx);
	if (game->monster)
		free(game->monster);
	ft_tab_free_content(&game->map);
	ft_printf("\nKeys Collected: %d/%d\nMove Count: %d\n\nThanks for Playing !!\n", \
		game->collected, game->collected + game->obj.c_count, (int)game->moves);
	exit(0);
}

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

void	destroy_img(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < TEXTURES)
		if (mlx->img[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->img[i]);
}
