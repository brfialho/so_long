/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_learning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/29 21:47:28 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct	s_mlx_img{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}				t_mlx_img;

typedef struct	s_mlx {
	t_mlx_img		img;
	void			*mlx_ptr;
	void			*win_ptr;
	struct timeval	key_press_time[ASCII];
	unsigned char	key_is_pressed[ASCII];
	t_position		square;
}				t_mlx;

void	pixel_put(t_mlx_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	free_mlx(t_mlx *mlx, int exit_program)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	if (exit_program)
		exit(0);
	return (0);
}

unsigned int	get_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((unsigned int)r << 16 | g << 8 | b);
}

void	full_color(t_mlx mlx)
{
	// static unsigned char r = 0, g = 0, b = 0;

	// r += 255;
	// g += 63;
	// b += 127;
	for (int y = 0; y < mlx.img.height; y++)
		for (int x = 0; x < mlx.img.width; x++)
			pixel_put(&mlx.img, x, y, get_rgb(0, 0, 0));
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	struct timeval	now;
	long			time_passed;

	keycode = (unsigned char)keycode;
	gettimeofday(&now, NULL);

	time_passed = (now.tv_sec - mlx->key_press_time[keycode].tv_sec) * 1000000
					+ now.tv_usec - mlx->key_press_time[keycode].tv_usec;
	if (time_passed > 10000)
		mlx->key_is_pressed[keycode] = FALSE;
	if (!mlx->key_is_pressed[keycode])
	{
		mlx->key_press_time[keycode] = now;
		mlx->key_is_pressed[keycode] = TRUE;
		if (keycode == ESC)
			return (free_mlx(mlx, TRUE));
		if (keycode == 'W' || keycode == 'w')
			// return (move_square(mlx, 1), 0);
			mlx->square.row -= 10;
		if (keycode == 'A' || keycode == 'a')
			// return (move_square(mlx, 2), 0);
			mlx->square.col -= 10;
		if (keycode == 'S' || keycode == 's')
			// return (move_square(mlx, 3), 0);
			mlx->square.row += 10;
		if (keycode == 'D' || keycode == 'd')
			// return (move_square(mlx, 4), 0);
			mlx->square.col += 10;
	}
	printf("KEY IS PRESSED:%u %hhu\n", keycode, mlx->key_is_pressed[keycode]);
	return (0);
}

int	window_destoy(t_mlx *mlx)
{
	return (free_mlx(mlx, TRUE));
}

int	render_square(t_mlx *mlx)
{
	full_color(*mlx);
	for (int y = 0; y < 40; y++)
		for (int x = 0; x < 40; x++)
			pixel_put(&mlx->img, mlx->square.col + x, mlx->square.row + y, get_rgb(255, 0, 0));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (0);	
}

int	main(void)
{
	t_mlx mlx;

	mlx.img.width = 800;
	mlx.img.height = 600;
	ft_bzero(mlx.key_is_pressed, sizeof(mlx.key_is_pressed));
	ft_bzero(mlx.key_press_time, sizeof(mlx.key_press_time));

	mlx.square.row = 400;
	mlx.square.col = 300;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.img.width, mlx.img.height, "Hello world!");

	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.img.width, mlx.img.height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.size_line, &mlx.img.endian);
	
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, &mlx);
	// mlx_hook(mlx.win_ptr, 3, 1L << 3, key_release, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, window_destoy, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, render_square, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

// 	Organize structs

