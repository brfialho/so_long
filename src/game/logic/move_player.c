/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:51:36 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_player(t_game *game, t_pos next_pos)
{
	char		next_tile;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL)
		return ;
	ft_printf("Movement counter: %d\n", ++game->moves);
	if (next_tile == QUEST)
		game->obj.c_count--;
	if (next_tile == EXIT
		&& !game->obj.c_count)
		destroy_game(game);
	((char **)game->map.tab)[next_pos.row][next_pos.col] = PLAYER;
	((char **)game->map.tab)[game->player.row][game->player.col] = FLOOR;
	if (game->player.row == game->exit.row
		&& game->player.col == game->exit.col)
		((char **)game->map.tab)[game->player.row][game->player.col] = EXIT;
	game->player = next_pos;
}
