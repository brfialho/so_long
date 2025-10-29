/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_learning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/29 17:39:35 by brfialho         ###   ########.fr       */
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
	void		*win_ptr;
	struct timeval time;
	unsigned char keys_pressed[127];
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
	static unsigned char r = 0, g = 0, b = 0;

	r += 255;
	g += 63;
	b += 127;
	for (int y = 0; y < mlx.img.height - 1; y++)
		for (int x = 0; x < mlx.img.width - 1; x++)
			pixel_put(&mlx.img, x, y, get_rgb(r, g, b));
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	keycode = (unsigned char)keycode;
	gettimeofday(&mlx->time, NULL);
	// mlx->keys_pressed[keycode] = 1;
	if (keycode == ESC)
		return (free_mlx(mlx, TRUE));
	if (keycode == 'W' || keycode == 'w')
		return (full_color(*mlx), 0);
	return (0);
}

// int	key_release(int keycode, t_mlx *mlx)
// {
// 	long	tmp;

// 	tmp = (long)mlx->time.tv_sec;
// 	gettimeofday(&mlx->time, NULL);
// 	if ((long)mlx->time.tv_sec - tmp > 3)
// 		ft_printf("SO LONG\n");
// 	return (0);
// 	(void)keycode;
// }

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x >= mlx->img.width || y >= mlx->img.height)
		return (0);
	pixel_put(&mlx->img, x, y, get_rgb(255, 0 ,0));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (0);
	(void)button;
}

int	window_destoy(t_mlx *mlx)
{
	return (free_mlx(mlx, TRUE));
}

int	mouse_in(int x, int y, t_mlx *mlx)
{
	return(printf("HELLO\n"));
	(void)mlx;
	(void)x;
	(void)y;
}

int	mouse_out(int x, int y, t_mlx *mlx)
{
	return(printf("BYE\n"));
	(void)mlx;
	(void)x;
	(void)y;
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


// typedef struct  s_t{
// 	int x;
// 	int y;
// } t_t;

// typedef struct  s_teste{
// 	int a;
// 	t_t t;
// }t_teste;


// void teste(t_teste t)
// {
// 	printf ("AAA %d %d %d\n", t.a, t.t.x, t.t.y);
// }
int	main(void)
{
	t_mlx mlx;

	mlx.img.width = 800;
	mlx.img.height = 600;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.img.width, mlx.img.height, "Hello world!");

	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.img.width, mlx.img.height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.size_line, &mlx.img.endian);

	full_color(mlx);
	
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, &mlx);
	// mlx_hook(mlx.win_ptr, 3, 1L << 3, key_release, &mlx);
	mlx_hook(mlx.win_ptr, 8, 1L << 5, mouse_out, &mlx);
	mlx_hook(mlx.win_ptr, 4, 1L << 2, mouse_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, window_destoy, &mlx);
	mlx_hook(mlx.win_ptr, 7, 1L << 4, mouse_in, &mlx);
	mlx_hook(mlx.win_ptr, 8, 1L << 5, mouse_out, &mlx);
	mlx_loop(mlx.mlx_ptr);

	// t_teste t;
	// t.a = 10;
	// t.t.x = 20;
	// t.t.y = 30;
	// teste (t);
}

// 	Organize structs


//  try hooks