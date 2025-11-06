/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:21:14 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:19:36 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	destroy_img(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < TEXTURES)
		if (mlx->img[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->img[i]);
}
