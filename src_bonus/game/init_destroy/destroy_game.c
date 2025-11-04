/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 18:36:18 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	destroy_game(t_game *game)
{
	if (game->mlx.mlx_ptr)
		destroy_mlx(&game->mlx, TRUE, TRUE);
	if (game->monster)
		free(game->monster);
	ft_tab_free_content(&game->map);
	ft_printf("\nThanks for Playing !!\n");
	exit(0);
}
