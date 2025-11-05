/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:27:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 16:22:15 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	init_mlx_display(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (FALSE);
	mlx->win_ptr = mlx_new_window(\
					mlx->mlx_ptr, \
					mlx->total_width, \
					mlx->total_height, \
					"True So Long!");
	if (!mlx->win_ptr)
		return (destroy_mlx(mlx, FALSE, FALSE));
	mlx->img[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/monster_down.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img[0])
		return (destroy_mlx(mlx, TRUE, TRUE));
	return (TRUE);
}
