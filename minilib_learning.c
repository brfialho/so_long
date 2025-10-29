/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_learning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/28 21:48:24 by brfialho         ###   ########.fr       */
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
	t_mlx_img	img;
	void		*mlx_ptr;
	void		*window;
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
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
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

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		return (free_mlx(mlx, TRUE));
	return (0);
}

// int	mouse_on_screen(int x, int y, t_mlx *mlx)
// {
// 	for (int a = 0; a < mlx->img.height - 1; a++)
// 		for (int b = 0; b < mlx->img.width - 1; b++)
// 			pixel_put(&mlx->img, b, a, get_rgb(0, 0, 255));
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->img.img_ptr, 
// 							(WIDTH - mlx->img.width) / 2, (HEIGHT - mlx->img.height) / 2);
// 	(void)x;
// 	(void)y;
// 	return (0);
// }


int	main(void)
{
	t_mlx mlx;

	mlx.img.width = 100;
	mlx.img.height = 100;

	mlx.mlx_ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Hello world!");

	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.size_line,&mlx.img.endian);
	for (int y = 0; y < mlx.img.height - 1; y++)
		for (int x = 0; x < mlx.img.width - 1; x++)
			pixel_put(&mlx.img, x, y, get_rgb(0, 0, 255));
	for (int y = 0; y < mlx.img.height - 1; y++)
		for (int x = 0; x < mlx.img.width - 1; x++)
			pixel_put(&mlx.img, x + 50, y, get_rgb(255, 0, 0));
			// if (!x)
	        // 	my_mlx_pixel_put(&img, x, y, c++);
			// else if (!y)
	        // 	my_mlx_pixel_put(&img, x, y, c = c + c);
			// else if (x == 100 - 1)
	        // 	my_mlx_pixel_put(&img, x, y, c = c + 256);
			// else if (y == 100 - 1)
	        // 	my_mlx_pixel_put(&img, x, y, c = c + 127);
			// else
			// 	my_mlx_pixel_put(&img, x, y, c = c + c + c);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.img.img_ptr, (WIDTH - mlx.img.width) / 2, (HEIGHT - mlx.img.height) / 2);

	mlx_hook(mlx.window, 2, 1L << 0, key_press, &mlx);
	// mlx_hook(mlx.window, 7, 1L << 4, mouse_on_screen, &mlx);

	for (int y = 0; y < mlx.img.height - 1; y++)
		for (int x = 0; x < mlx.img.width - 1; x++)
			pixel_put(&mlx.img, x + 50, y, get_rgb(0, 255, 0));
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.img.img_ptr, (WIDTH - mlx.img.width) / 2, (HEIGHT - mlx.img.height) / 2);
	mlx_loop(mlx.mlx_ptr);
}

// 	Organize structs
//  try hooks