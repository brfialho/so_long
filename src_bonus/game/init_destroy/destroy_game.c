/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:58:17 by brfialho         ###   ########.fr       */
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
	ft_printf("\nFinal Score: %d\nThanks for Playing !!\n", (int)game->moves);
	exit(0);
}
