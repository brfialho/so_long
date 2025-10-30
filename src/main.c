/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/30 18:43:58 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_mlx_data(t_game *game)
{
	game->mlx.height = (int)game->map.rows * 64;
	game->mlx.width = (int)game->map.cols * 64;
	ft_bzero(game->mlx.key_is_pressed, sizeof(game->mlx.key_is_pressed));
	ft_bzero(game->mlx.key_press_time, sizeof(game->mlx.key_press_time));
}

int	init_mlx_display(t_mlx	*mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (FALSE);
	mlx->win_ptr = mlx_new_window( \
	mlx->mlx_ptr, mlx->width, mlx->height, "So Long!");
	if (!mlx->win_ptr)
		return (destroy_mlx(mlx, FALSE, FALSE));
	mlx->img.img_ptr =  mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (!mlx->img.img_ptr)
		return (destroy_mlx(mlx, TRUE, FALSE));
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
	if (!mlx->img.addr)
		return (destroy_mlx(mlx, TRUE, TRUE));
	return (TRUE);
}

void	init_game(t_game *game)
{
	// init_game_data(game);
	init_mlx_data(game);
	if (!init_mlx_display(&game->mlx))
	{
		ft_tab_free_content(&game->map);
		exit(1);
	}
}

int	destroy_game(t_game *game)
{
	destroy_mlx(&game->mlx, TRUE, TRUE);
	ft_tab_free_content(&game->map);
	ft_printf("Thanks for Playing !!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	map_parser(&game.map, argc, argv);
	map_validator(&game.map);
	
	ft_split_print((char **)game.map.tab);

	init_game(&game);


	mlx_hook(game.mlx.win_ptr, 17, 1L << 17, destroy_game, &game);
	mlx_loop(game.mlx.mlx_ptr);
}