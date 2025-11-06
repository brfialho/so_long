/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:23:00 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	set_player(t_game *game, t_pos pos, t_direction direction);

void	move_player(t_game *game, t_pos next_pos, t_direction e_direction)
{
	char		next_tile;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL)
		return ;
	if (next_tile == QUEST)
		game->obj.c_count--;
	if ((next_tile == EXIT && !game->obj.c_count)
		|| (ft_strchr(MONSTER_SET, next_tile) && ft_printf ("\n\n ### GAME OVER ###\n\n")))
		destroy_game(game);
	set_player(game, next_pos, e_direction);
	((char **)game->map.tab)[game->player.row][game->player.col] = FLOOR;
	if (pos_cmp(game->player, game->exit))
		((char **)game->map.tab)[game->player.row][game->player.col] = EXIT;
	game->player = next_pos;
	game->moves++;
}

static void	set_player(t_game *game, t_pos pos, t_direction direction)
{
	if (direction == LEFT)
		((char **)game->map.tab)[pos.row][pos.col] = PLAYER_LEFT;
	else if (direction == RIGHT)
		((char **)game->map.tab)[pos.row][pos.col] = PLAYER_RIGHT;
	else
		((char **)game->map.tab)[pos.row][pos.col] = PLAYER;
}
