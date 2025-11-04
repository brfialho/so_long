/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:25:47 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 18:41:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	find_monsters(t_game *game);

void	init_game(t_game *game)
{
	game->moves = 0;
	game->mlx.height = (int)game->map.rows * SQUARE;
	game->mlx.width = (int)game->map.cols * SQUARE;
	ft_bzero(game->mlx.key_is_pressed, sizeof(game->mlx.key_is_pressed));
	if (!init_mlx_display(&game->mlx))
		destroy_game(game);
	game->monster = ft_calloc(game->obj.x_count, sizeof(t_monster));
	if (!game->monster)
		destroy_game(game);
	find_monsters(game);
}

static void	find_monsters(t_game *game)
{
	int	i;
	int	j;
	int m;

	m = 0;
	i = -1;
	while (++i < (int)game->map.rows)
	{
		j = -1;
		while (++j < (int)game->map.cols)
			if (((char **)game->map.tab)[i][j] == ENEMY)
				game->monster[m++].pos = (t_pos){i, j};
	}
}
