/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:04:32 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:04:48 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	count_frame(t_game *game)
{
	game->frame++;
	if (game->frame > FRAME_MAX)
		game->frame = 0;
}
