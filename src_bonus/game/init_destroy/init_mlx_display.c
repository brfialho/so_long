/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:27:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 18:30:38 by brfialho         ###   ########.fr       */
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
		return (FALSE);
	return (TRUE);
}
