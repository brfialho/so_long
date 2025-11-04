/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 20:29:24 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	move_player(t_game *game, t_pos next_pos)
{
	char		next_tile;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL)
		return ;
	if (next_tile == QUEST)
		game->obj.c_count--;
	if ((next_tile == EXIT && !game->obj.c_count)
		|| (next_tile == ENEMY && ft_printf ("\n\n ### GAME OVER ###\n\n")))
		destroy_game(game);
	((char **)game->map.tab)[next_pos.row][next_pos.col] = PLAYER;
	((char **)game->map.tab)[game->player.row][game->player.col] = FLOOR;
	if (pos_cmp(game->player, game->exit))
		((char **)game->map.tab)[game->player.row][game->player.col] = EXIT;
	game->player = next_pos;
	game->moves++;
}
