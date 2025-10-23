/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_error_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:03:18 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:51:07 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	validator_error_handler(t_tab *map, e_error error)
{
	ft_split_free((char **)map->tab);
	if (error == MEMORY)
		ft_printf("Error\nNot enough memory\n");
	if (error == SIZE)
		ft_printf("Error\nInvalid map : size\n");
	if (error == BORDER)
		ft_printf("Error\nInvalid map : border\n");
	if (error == CHARS)
		ft_printf("Error\nInvalid map : unallowed chars\n");
	if (error == COUNT)
		ft_printf("Error\nInvalid map : wrong number of players/colectables/exits\n");
	if (error == PATH)
		ft_printf("Error\nInvalid map : invalid path\n");
	exit(1);
}
