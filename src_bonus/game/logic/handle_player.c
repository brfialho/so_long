/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:10:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/07 18:10:42 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	handle_player(t_game *game)
{
	if (game->mlx.key_is_pressed[ESC])
		destroy_game(game);
	if (game->mlx.key_is_pressed['W'] || game->mlx.key_is_pressed['w'])
		move_player(game, (t_pos){game->player.row - 1, game->player.col}, \
					UP);
	else if (game->mlx.key_is_pressed['A'] || game->mlx.key_is_pressed['a'])
		move_player(game, (t_pos){game->player.row, game->player.col - 1}, \
					LEFT);
	else if (game->mlx.key_is_pressed['S'] || game->mlx.key_is_pressed['s'])
		move_player(game, (t_pos){game->player.row + 1, game->player.col}, \
					DOWN);
	else if (game->mlx.key_is_pressed['D'] || game->mlx.key_is_pressed['d'])
		move_player(game, (t_pos){game->player.row, game->player.col + 1}, \
					RIGHT);
}
