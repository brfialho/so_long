/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:35:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:26:26 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	set_monster(t_game *game, t_pos_monster pos);

void	move_monster(t_game *game, t_pos_monster next_pos, int i)
{
	char		next_tile;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL || ft_strchr(MONSTER_SET, next_tile))
		return ;
	if (next_tile == QUEST || game->monster[i].quest_eaten)
		game->monster[i].quest_eaten++;
	if (ft_strchr(PLAYER_SET, next_tile))
		game_over(game);
	set_monster(game, next_pos);
	((char **)game->map.tab)[game->monster[i].pos.row][game->monster[i].pos.col] = FLOOR;
	if (pos_cmp(game->monster[i].pos, game->exit))
		((char **)game->map.tab)[game->monster[i].pos.row][game->monster[i].pos.col] = EXIT;
	if (game->monster[i].quest_eaten == 2)
	{
		((char **)game->map.tab)[game->monster[i].pos.row][game->monster[i].pos.col] = QUEST;
		game->monster[i].quest_eaten = 0;
	}
	game->monster[i].pos = (t_pos){next_pos.row, next_pos.col};
}
static void	set_monster(t_game *game, t_pos_monster pos)
{
	if (pos.direction == LEFT)
		((char **)game->map.tab)[pos.row][pos.col] = MONSTER_LEFT;
	else if (pos.direction == RIGHT)
		((char **)game->map.tab)[pos.row][pos.col] = MONSTER_RIGHT;
	else
		((char **)game->map.tab)[pos.row][pos.col] = MONSTER;
}