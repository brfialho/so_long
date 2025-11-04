/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:43:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	draw_square(t_mlx mlx, int row, int col, t_uint color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SQUARE)
	{
		x = -1;
		while (++x < SQUARE)
			pixel_put(&mlx.img, col * SQUARE + x, row * SQUARE + y, color);
	}
}
