/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/24 18:31:44 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_tab	map;

	parser(&map, argc, argv);
	validator(&map);
	ft_split_print((char **)map.tab);

	ft_tab_free_content(&map);
}