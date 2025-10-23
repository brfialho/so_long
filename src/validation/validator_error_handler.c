/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_error_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:03:18 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:03:29 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	validator_error_handler(t_tab *map)
{
	ft_split_free((char **)map->tab);
	ft_printf("Invalid Map\n");
	exit(1);
}
