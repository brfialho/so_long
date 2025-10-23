/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:04:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:42:46 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_size(t_tab *map)
{
	if (map->rows < 3 || map->cols < 3)
		validator_error_handler(map, SIZE);
}
