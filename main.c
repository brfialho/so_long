/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/21 21:57:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	main(void)
// {
// 	void	*mlx = mlx_init();
// 	void	*mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);

// 	free(mlx_win);
// 	free(mlx);
// }

int	main(int argc, char **argv)
{

	int fd = open("file.txt", O_RDONLY);
	// perror("Something went wrong");
	printf("ERROR : %s\n", strerror(errno));

	(void)fd;
	(void)argc;
	(void)argv;
}
