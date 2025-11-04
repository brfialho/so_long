/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:44:39 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 18:45:06 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

// t_pos	get_ramdom_move(t_pos next)
// {
// 	int	min;
// 	int	max;
// 	int ramdom;

// 	min = 1;
// 	max = 4;

// 	ramdom = (rand() % (max - min + 1)) + min;
// 	if (ramdom == 1)
// 		return ((t_pos){next.row - 1, next.col});
// 	else if (ramdom == 2)
// 		return ((t_pos){next.row, next.col});
// 	else if (ramdom == 3)
// 		return ((t_pos){next.row, next.col});
// 	else
// 		return ((t_pos){next.row, next.col});
// }


// void	move_monster(t_game *game, t_pos next_pos)
// {
// 	char		next_tile;

// 	next_tile = ((char **)game->map.tab)[next_pos.row][next_pos.col];
// 	if (next_tile == WALL)
// 		return ;
// 	((char **)game->map.tab)[next_pos.row][next_pos.col] = PLAYER;
// 	((char **)game->map.tab)[game->player.row][game->player.col] = FLOOR;
// 	if (game->player.row == game->exit.row
// 		&& game->player.col == game->exit.col)
// 		((char **)game->map.tab)[game->player.row][game->player.col] = EXIT;
// 	game->player = next_pos;
// }

// void	handle_monsters(t_game *game)
// {
// 	int			i;
// 	t_direction	d;

// 	i = -1;
// 	while (++i < game->obj.x_count)
// 		{
			
// 		}
// }

int	game_loop(t_game *game)
{
	handle_keys(game);
	all_key_release(game);
	// handle_monsters(game);
	render_image(game);
	ft_usleep(10000);
	return (0);
}
