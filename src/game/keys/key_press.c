/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:07:05 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 19:07:14 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int key_press(int keycode, t_game *game)
{
	game->mlx.key_is_pressed[(unsigned char)keycode] = TRUE;
	return (0);
}
