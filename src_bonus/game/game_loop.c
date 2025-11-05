/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:44:SPEED - 1 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 18:45:06 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

t_pos	get_ramdom_move(t_pos next)
{
	int	min;
	int	max;
	int ramdom;

	min = 1;
	max = 4;

	ramdom = (rand() % (max - min + 1)) + min;
	if (ramdom == 1)
		return ((t_pos){next.row - 1, next.col});
	if (ramdom == 2)
		return ((t_pos){next.row, next.col + 1});
	if (ramdom == 3)
		return ((t_pos){next.row + 1, next.col});
	return ((t_pos){next.row, next.col - 1});
}


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

void	handle_monsters(t_game *game)
{
	static int	cooldown = 0;
	int			i;

	if (cooldown++ < SPEED)
		return ;
	cooldown = 0;
	i = -1;
	while (++i < (int)game->obj.x_count)
		move_monster(game, get_ramdom_move(game->monster[i].pos), i);
}


int	game_loop(t_game *game)
{
	handle_keys(game);
	all_key_release(game);
	handle_monsters(game);
	render_image(game);
	display_moves(game);
	ft_usleep(10000);
	return (0);
}
