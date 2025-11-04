/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_key_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:07:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/04 16:40:00 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	all_key_release(t_game *game)
{
	int	keycode;

	keycode = 0;
	while (keycode < ASCII)
		game->mlx.key_is_pressed[keycode++] = FALSE;
}
