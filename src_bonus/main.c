/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	map_parser(&game.map, argc, argv);
	map_validator(&game);
	init_game(&game);
	ft_printf("\n####### Welcome to brfialho so_long !! #######\n\n");
	mlx_hook(game.mlx.win_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win_ptr, 17, 1L << 17, destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
