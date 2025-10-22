/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/22 14:27:55 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error\n"));

	int fd = open(argv[1], O_RDONLY);

	if (fd < 0)
		return (ft_printf("Error : %s\n", strerror(errno)));
	
	t_tab	map;
	if (!ft_tab_innit_empty(&map, 5, 15, sizeof(char)))
		return (1);
	int i = -1;
	while ((map.tab[++i] = get_next_line(fd)))
		;
	for (int j = 0; j < i; j++)
		ft_printf("LINE: %d LEN: %s", ft_strlen(map.tab[j]), map.tab[j]);
	ft_tab_free_content(&map);
}
