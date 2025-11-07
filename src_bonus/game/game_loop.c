/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:44:12 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 21:27:00 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	game_loop(t_game *game)
{
	handle_player(game);
	all_key_release(game);
	handle_monsters(game);
	render_image(game);
	count_frame(game);
	ft_usleep(10000);
	return (0);
}
