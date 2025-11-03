/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:43:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 19:27:59 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_square(t_mlx mlx, int row, int col, u_int color)
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
