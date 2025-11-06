/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:00:32 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 17:09:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	display_moves(t_game *game)
{
	char	*moves;
	char	*msg;

	moves = ft_itoa(game->moves);
	if (!moves)
		destroy_game(game);
	msg = ft_strjoin("Movement Counter: ", moves);
	free(moves);
	if (!msg)
		destroy_game(game);
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, \
					SQUARE, SQUARE / 2, 0x00FF00, msg);
	free(msg);
}
