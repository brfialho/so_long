/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/21 22:49:54 by brfialho         ###   ########.fr       */
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
	
	char *lines[6];
	int i = 0;
	while ((lines[i] = get_next_line(fd)))
		ft_printf("LINE: %s\n", lines[i++]);
}
