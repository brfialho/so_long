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
