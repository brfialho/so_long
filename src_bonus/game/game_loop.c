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

// int	get_ramdom_pos(void)
// {
// 	int	min;
// 	int	max;
// 	int ramdom;

// 	min = 1;
// 	max = 4;

// 	ramdom = (rand() % (max - min + 1)) + min;
// 	return (ramdom);
// }

// void move_monsters(t_game *game)
// {
// 	game = 0;
// 	get_ramdom_pos();
// }


// void	handle_monsters(t_game *game)
// {
// 	move_monsters(game);
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
