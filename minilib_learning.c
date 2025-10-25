/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_learning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/24 22:21:16 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct	s_mlx_img{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_mlx_img;

void	pixel_put(t_mlx_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((unsigned int)r << 16 | g << 8 | b);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_img	img;

	int width = 100;
	int height = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");

	img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line,&img.endian);
	for (int y = 0; y < height - 1; y++)
		for (int x = 0; x < width - 1; x++)
			pixel_put(&img, x, y, get_rgb(0, 0, 255));
	for (int y = 0; y < height - 1; y++)
		for (int x = 0; x < width - 1; x++)
			pixel_put(&img, x + 50, y, get_rgb(255, 0, 0));
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
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, (WIDTH - width) / 2, (HEIGHT - height) / 2);

	mlx_loop(mlx);
}