/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_learning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/31 17:38:51 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"









// void	full_color(t_mlx mlx)
// {
// 	// static unsigned char r = 0, g = 0, b = 0;

// 	// r += 255;
// 	// g += 63;
// 	// b += 127;
// 	for (int y = 0; y < mlx.img.height; y++)
// 		for (int x = 0; x < mlx.img.width; x++)
// 			pixel_put(&mlx.img, x, y, get_rgb(0, 0, 0));
// 	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
// }

// int	key_press(int keycode, t_mlx *mlx)
// {
// 	struct timeval	now;
// 	long			time_passed;

// 	keycode = (unsigned char)keycode;
// 	gettimeofday(&now, NULL);

// 	time_passed = (now.tv_sec - mlx->key_press_time[keycode].tv_sec) * 1000000
// 					+ now.tv_usec - mlx->key_press_time[keycode].tv_usec;
// 	if (time_passed > 10000)
// 		mlx->key_is_pressed[keycode] = FALSE;
// 	if (!mlx->key_is_pressed[keycode])
// 	{
// 		mlx->key_press_time[keycode] = now;
// 		mlx->key_is_pressed[keycode] = TRUE;
// 		if (keycode == ESC)
// 			return (free_mlx(mlx, TRUE));
// 		if (keycode == 'W' || keycode == 'w')
// 			// return (move_square(mlx, 1), 0);
// 			mlx->square.row -= 10;
// 		if (keycode == 'A' || keycode == 'a')
// 			// return (move_square(mlx, 2), 0);
// 			mlx->square.col -= 10;
// 		if (keycode == 'S' || keycode == 's')
// 			// return (move_square(mlx, 3), 0);
// 			mlx->square.row += 10;
// 		if (keycode == 'D' || keycode == 'd')
// 			// return (move_square(mlx, 4), 0);
// 			mlx->square.col += 10;
// 	}
// 	printf("KEY IS PRESSED:%u %hhu\n", keycode, mlx->key_is_pressed[keycode]);
// 	return (0);
// }

// int	window_destoy(t_mlx *mlx)
// {
// 	return (free_mlx(mlx, TRUE));
// }

// int	render_square(t_mlx *mlx)
// {
// 	full_color(*mlx);
// 	for (int y = 0; y < 40; y++)
// 		for (int x = 0; x < 40; x++)
// 			pixel_put(&mlx->img, mlx->square.col + x, mlx->square.row + y, get_rgb(255, 0, 0));
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
// 	return (0);	
// }

// int	main(void)
// {
// 	t_mlx mlx;

// 	mlx.img.width = 800;
// 	mlx.img.height = 600;
// 	ft_bzero(mlx.key_is_pressed, sizeof(mlx.key_is_pressed));
// 	ft_bzero(mlx.key_press_time, sizeof(mlx.key_press_time));

// 	mlx.square.row = 400;
// 	mlx.square.col = 300;

// 	mlx.mlx_ptr = mlx_init();
// 	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.img.width, mlx.img.height, "Hello world!");

// 	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.img.width, mlx.img.height);
// 	mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.size_line, &mlx.img.endian);
	
// 	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, &mlx);
// 	// mlx_hook(mlx.win_ptr, 3, 1L << 3, key_release, &mlx);
// 	mlx_hook(mlx.win_ptr, 17, 1L << 17, window_destoy, &mlx);
// 	mlx_loop_hook(mlx.mlx_ptr, render_square, &mlx);
// 	mlx_loop(mlx.mlx_ptr);
// }


int key_release(t_mlx *mlx);

int	key_press(int keycode, t_mlx *mlx)
{
	// struct timeval	now;
	// long			time_passed;

	keycode = (char)keycode;
	// gettimeofday(&now, NULL);
	// time_passed = (now.tv_sec - mlx->key_press_time[keycode].tv_sec) * 1000000
	// 				+ now.tv_usec - mlx->key_press_time[keycode].tv_usec;
	// printf("TIME: %ld\n", time_passed);
	// if (time_passed > 10000)
	// 	mlx->key_is_pressed[keycode] = FALSE;
	// if (!mlx->key_is_pressed[keycode])
	// {
	// 	mlx->key_press_time[keycode] = now;
	// 	mlx->key_is_pressed[keycode] = TRUE;
	// }
	// printf("ON PRESS -> CHAR: %c PRESS: %d\n", (unsigned char)keycode, mlx->key_is_pressed[keycode]);

	mlx->key_is_pressed[keycode] = TRUE;
	// printf("%d\n", mlx->key_is_pressed['w']);

	return (0);
}

int print_pressed(t_mlx *mlx)
{
	// int x = -1;
	// while (++x < ASCII)
	// 	if (mlx->key_is_pressed[x])
	// 		printf("CHAR %c %d\n", (unsigned char)x, mlx->key_is_pressed[x]);
	printf("%d\n", mlx->key_is_pressed['w']);
	key_release(mlx);
	return (0);
}

int key_release(t_mlx *mlx)
{
	my_usleep(100000);
	int keycode = 0;
	
	while (keycode < ASCII)
		mlx->key_is_pressed[keycode++] = FALSE;
	// printf("ON RELEASE -> CHAR: %c PRESS: %d\n", (unsigned char)keycode, mlx->key_is_pressed[keycode]); 
	return (0);
}



int main(void)
{
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 100, 100, "TESTE");
	ft_bzero(mlx.key_is_pressed, sizeof(mlx.key_is_pressed));
	ft_bzero(mlx.key_press_time, sizeof(mlx.key_is_pressed));

	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, print_pressed, &mlx);
	mlx_loop(mlx.mlx_ptr);
}


// int key_release(int keycode, void *test)
// {
// 	printf("ON RELEASE -> CHAR: %c\n", (unsigned char)keycode);
// 	(void)test;
// 	return (0);
// }

// int key_press(int keycode, void *test)
// {
// 	printf("ON PRESS -> CHAR: %c\n", (unsigned char)keycode);
// 	(void)test;
// 	return (0);
// }

// int main (void)
// {

// 	void *mlx = mlx_init();
// 	void *win_ptr = mlx_new_window(mlx, 100, 100, "TESTE");

// 	mlx_hook(win_ptr, 3, 1L << 3, key_release, &mlx);
// 	mlx_hook(win_ptr, 2, 1L << 0, key_press, &mlx);
// 	mlx_loop(mlx);
// 	(void)win_ptr;
// }