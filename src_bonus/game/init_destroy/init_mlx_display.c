/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:27:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:35:46 by brfialho         ###   ########.fr       */
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
					mlx->width, \
					mlx->height, \
					"True So Long!");
	if (!mlx->win_ptr)
		return (destroy_mlx(mlx, FALSE, FALSE));
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (!mlx->img.img_ptr)
		return (destroy_mlx(mlx, TRUE, FALSE));
	mlx->img.addr = mlx_get_data_addr(\
					mlx->img.img_ptr, \
					&mlx->img.bits_per_pixel, \
					&mlx->img.size_line, \
					&mlx->img.endian);
	if (!mlx->img.addr)
		return (destroy_mlx(mlx, TRUE, TRUE));
	return (TRUE);
}
