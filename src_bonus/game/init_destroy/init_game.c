/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:25:47 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/22 12:53:07 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	find_monsters(t_game *game);
static void	mutate_monsters(t_game *game);

void	init_game(t_game *game)
{
	ft_bzero(&game->mlx, sizeof(game->mlx));
	game->moves = 0;
	game->frame = 0;
	game->collected = 0;
	game->mlx.total_height = (int)game->map.rows * SQUARE;
	game->mlx.total_width = (int)game->map.cols * SQUARE;
	if (!init_mlx_display(&game->mlx))
		destroy_game(game);
	if (!init_img(&game->mlx))
		destroy_game(game);
	game->monster = ft_calloc(game->obj.x_count, sizeof(t_monster));
	if (!game->monster)
		destroy_game(game);
	find_monsters(game);
	mutate_monsters(game);
}

static void	find_monsters(t_game *game)
{
	int	i;
	int	j;
	int	m;

	m = 0;
	i = -1;
	while (++i < (int)game->map.rows)
	{
		j = -1;
		while (++j < (int)game->map.cols)
			if (((char **)game->map.tab)[i][j] == MONSTER)
				game->monster[m++].pos = (t_pos){i, j};
	}
}

void	mutate_monsters(t_game *game)
{
	int	i;

	i = -1;
	while (++i < (int)game->obj.x_count)
	{
		if (!((game->monster[i].pos.row + game->monster[i].pos.col) % 3))
		{
			game->monster[i].type = CRAZY;
			((char **)game->map.tab) \
			[game->monster[i].pos.row][game->monster[i].pos.col] = CRAZY;
		}
		else
			game->monster[i].type = MONSTER;
	}
}
