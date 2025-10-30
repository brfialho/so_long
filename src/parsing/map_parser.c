/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:53:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/24 16:11:40 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	map_parser(t_tab *map, int argc, char **argv)
{
	int		fd;
	char	**lines;

	if (argc != 2)
		parser_error_handler(0, NULL, USAGE);
	if (!valid_file_name(argv[1]))
		parser_error_handler(0, NULL, NAME);
	fd = open(argv[1], O_RDONLY);	
	if (fd == -1)
		parser_error_handler(0, NULL, READ);
	lines = read_lines(fd);
	if (!lines)
		parser_error_handler(fd, NULL, EMPTY);
	if (!is_rectangular(lines))
		parser_error_handler(fd, lines, RECTANGULAR);
	map_init(map, lines);
	close(fd);
}
