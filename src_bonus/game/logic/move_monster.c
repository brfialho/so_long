/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:35:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/07 18:06:54 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	set_monster(t_game *game, t_pos_move pos, int m);

void	move_monster(t_game *game, t_pos_move next_pos, int m)
{
	char	next_tile;
	t_pos	monster_pos;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL || ft_strchr(MONSTER_SET, next_tile))
		return ;
	if (next_tile == QUEST || game->monster[m].quest_eaten)
		game->monster[m].quest_eaten++;
	if (ft_strchr(PLAYER_SET, next_tile))
		game_over(game);
	set_monster(game, next_pos, m);
	monster_pos = game->monster[m].pos;
	((char **)game->map.tab)[monster_pos.row][monster_pos.col] = FLOOR;
	if (pos_cmp(monster_pos, game->exit))
		((char **)game->map.tab)[monster_pos.row][monster_pos.col] = EXIT;
	if (game->monster[m].quest_eaten == 2)
	{
		((char **)game->map.tab)[monster_pos.row][monster_pos.col] = QUEST;
		game->monster[m].quest_eaten = 0;
	}
	game->monster[m].pos = (t_pos){next_pos.row, next_pos.col};
}

static void	set_monster(t_game *game, t_pos_move pos, int m)
{
	int	type;

	type = game->monster[m].type;
	if (pos.direction == LEFT && type == MONSTER)
			((char **)game->map.tab)[pos.row][pos.col] = MONSTER_LEFT;
	else if (pos.direction == LEFT && type == CRAZY)
			((char **)game->map.tab)[pos.row][pos.col] = CRAZY_LEFT;
	else if (pos.direction == RIGHT && type == MONSTER)
		((char **)game->map.tab)[pos.row][pos.col] = MONSTER_RIGHT;
	else if (pos.direction == RIGHT && type == CRAZY)
		((char **)game->map.tab)[pos.row][pos.col] = CRAZY_RIGHT;
	else if (type == MONSTER)
		((char **)game->map.tab)[pos.row][pos.col] = MONSTER;
	else if (type == CRAZY)
		((char **)game->map.tab)[pos.row][pos.col] = CRAZY;
}
