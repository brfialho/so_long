/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/06 16:56:00 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	destroy_game(t_game *game)
{
	destroy_mlx(&game->mlx, TRUE, TRUE);
	ft_tab_free_content(&game->map);
	ft_printf("\nScore : %d\nThanks for Playing !!\n\n", (int)game->moves);
	exit(0);
}
