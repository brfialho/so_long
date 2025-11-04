/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:06:43 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 18:36:52 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	handle_keys(t_game *game)
{
	if (game->mlx.key_is_pressed[ESC])
		destroy_game(game);
	if (game->mlx.key_is_pressed['W'] || game->mlx.key_is_pressed['w'])
		move_player(game, (t_pos){game->player.row - 1, game->player.col});
	else if (game->mlx.key_is_pressed['A'] || game->mlx.key_is_pressed['a'])
		move_player(game, (t_pos){game->player.row, game->player.col - 1});
	else if (game->mlx.key_is_pressed['S'] || game->mlx.key_is_pressed['s'])
		move_player(game, (t_pos){game->player.row + 1, game->player.col});
	else if (game->mlx.key_is_pressed['D'] || game->mlx.key_is_pressed['d'])
		move_player(game, (t_pos){game->player.row, game->player.col + 1});
}
