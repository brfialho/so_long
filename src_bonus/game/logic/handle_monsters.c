/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_monsters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:36:14 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 21:30:32 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static t_pos_monster	get_ramdom_move(t_pos next);

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

static t_pos_monster	get_ramdom_move(t_pos next)
{
	int	min;
	int	max;
	int	ramdom;

	min = 1;
	max = 4;
	ramdom = (rand() % (max - min + 1)) + min;
	if (ramdom == 1)
		return ((t_pos_monster){next.row - 1, next.col, UP});
	if (ramdom == 2)
		return ((t_pos_monster){next.row, next.col + 1, RIGHT});
	if (ramdom == 3)
		return ((t_pos_monster){next.row + 1, next.col, DOWN});
	return ((t_pos_monster){next.row, next.col - 1, LEFT});
}
