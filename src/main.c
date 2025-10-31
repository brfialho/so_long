/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/31 19:06:00 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	init_game_data(t_game *game)
{
	game->moves = 0;
	game->mlx.height = (int)game->map.rows * SQUARE;
	game->mlx.width = (int)game->map.cols * SQUARE;
	ft_bzero(game->mlx.key_is_pressed, sizeof(game->mlx.key_is_pressed));
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

int	destroy_game(t_game *game)
{
	destroy_mlx(&game->mlx, TRUE, TRUE);
	ft_tab_free_content(&game->map);
	ft_printf("\nThanks for Playing !!\n");
	exit(0);
}

void	init_game(t_game *game)
{
	init_game_data(game);
	if (!init_mlx_display(&game->mlx))
		destroy_game(game);
}


void	draw_square(t_mlx mlx, int row, int col, unsigned int color)
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

int	render_image(t_game *game)
{
	int	row;
	int	col;
	
	row = -1;
	while (++row < (int)game->map.rows)
	{
		col = -1;
		while (++col < (int)game->map.cols)
		{
			if (((char **)game->map.tab)[row][col] == PLAYER)
				draw_square(game->mlx, row, col, get_rgb(255, 0, 0));
			if (((char **)game->map.tab)[row][col] == QUEST)
				draw_square(game->mlx, row, col, get_rgb(255, 255, 0));
			if (((char **)game->map.tab)[row][col] == FLOOR)
				draw_square(game->mlx, row, col, get_rgb(128, 128, 128));
			if (((char **)game->map.tab)[row][col] == WALL)
				draw_square(game->mlx, row, col, get_rgb(0, 0, 0));
			if (((char **)game->map.tab)[row][col] == EXIT)
				draw_square(game->mlx, row, col, get_rgb(255, 255, 255));
		}
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.img_ptr, 0, 0);
	return (0);
}

void	move_player(t_game *game, t_pos next_pos)
{
	char		next_tile;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL)
		return ;
	if (next_tile == QUEST)
		game->obj.c_count--;
	if (next_tile == EXIT
		&& !game->obj.c_count)
		destroy_game(game);
	((char **)game->map.tab)[next_pos.row][next_pos.col] = PLAYER;
	((char **)game->map.tab)[game->player.row][game->player.col] = FLOOR;
	if (game->player.row == game->exit.row && game->player.col == game->exit.col)
		((char **)game->map.tab)[game->player.row][game->player.col] = EXIT;
	game->player = next_pos;
	ft_printf("Movement counter: %d\n", ++game->moves);
}

int key_press(int keycode, t_game *game)
{
	game->mlx.key_is_pressed[(unsigned char)keycode] = TRUE;
	return (0);
}

void	all_key_release(t_game *game)
{
	int	keycode;

	ft_usleep(10000);
	keycode = 0;
	while (keycode < ASCII)
		game->mlx.key_is_pressed[keycode++] = FALSE;
}

void	handle_keys(t_game *game)
{
	// printf("%d\n", game->mlx.key_is_pressed['w']);
	if (game->mlx.key_is_pressed[ESC])
		destroy_game(game);
	if (game->mlx.key_is_pressed['W'] || game->mlx.key_is_pressed['w'])
		move_player(game, (t_pos){game->player.row - 1, game->player.col});
	else if (game->mlx.key_is_pressed['A'] || game->mlx.key_is_pressed['a'])
		move_player(game, (t_pos){game->player.row, game->player.col - 1});
	else if (game->mlx.key_is_pressed['S'] || game->mlx.key_is_pressed['s'])
		move_player(game, (t_pos){game->player.row + 1, game->player.col});
	else if (game->mlx.key_is_pressed['D'] || game->mlx.key_is_pressed['d'])
		move_player(game, (t_pos){game->player.row, game->player.col + 1});
}

int	game_logic(t_game *game)
{
	handle_keys(game);
	all_key_release (game);
	render_image(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	map_parser(&game.map, argc, argv);
	map_validator(&game);
	init_game(&game);
	ft_printf("\n####### Welcome to brfialho so_long !! #######\n\n");
	mlx_hook(game.mlx.win_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win_ptr, 17, 1L << 17, destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_logic, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
