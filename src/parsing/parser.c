/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:53:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 17:53:40 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	parser(t_tab *map, char *map_file)
{
	int		fd;
	char	**lines;

	if (!valid_file_name(map_file))
		parser_error_handler(0, NULL);
	fd = open(map_file, O_RDONLY);	
	if (fd == -1)
		parser_error_handler(0, NULL);
	lines = read_lines(fd);
	if (!lines)
		parser_error_handler(fd, NULL);
	if (!is_rectangular(lines))
		parser_error_handler(fd, lines);
	map_init(map, lines);
	close(fd);
}
