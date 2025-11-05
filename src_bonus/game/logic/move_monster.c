/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:35:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 21:35:50 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	move_monster(t_game *game, t_pos next_pos, int i)
{
	char		next_tile;

	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
	if (next_tile == WALL || next_tile == ENEMY)
		return ;
	if (next_tile == QUEST || game->monster[i].quest_eaten)
		game->monster[i].quest_eaten++;
	if (next_tile == PLAYER && ft_printf ("\n\n ### GAME OVER ###\n\n"))
		destroy_game(game);
	((char **)game->map.tab)[next_pos.row][next_pos.col] = ENEMY;
	((char **)game->map.tab)[game->monster[i].pos.row][game->monster[i].pos.col] = FLOOR;
	if (pos_cmp(game->monster[i].pos, game->exit))
		((char **)game->map.tab)[game->monster[i].pos.row][game->monster[i].pos.col] = EXIT;
	if (game->monster[i].quest_eaten == 2)
	{
		((char **)game->map.tab)[game->monster[i].pos.row][game->monster[i].pos.col] = QUEST;
		game->monster[i].quest_eaten = 0;
	}
	game->monster[i].pos = next_pos;
}
