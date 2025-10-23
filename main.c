/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 17:22:10 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	parser_error_handler(int fd, char **split)
{
	if (fd)
		close(fd);
	if (split)
		ft_split_free(split);
	ft_printf("Error in parsing\n");
	exit(1);
}

int	valid_file_name(char *s)
{
	size_t len;

	len = ft_strlen(s);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(s + len - 4, ".ber", 4))
		return (FALSE);
	len -= 4;
	while (len)
		if (s[len-- - 1] == '.')
			return (FALSE);
	return(TRUE);
}

char	**read_lines(int fd)
{
	char	**lines;
	char	*buffer;
	char	*gnl;

	buffer = NULL;
	gnl = get_next_line(fd);
	while (gnl)
	{
		buffer = ft_strjoin_free(buffer, gnl);
		if (!buffer)
			return (NULL);
		gnl = get_next_line(fd);
	}
	lines = ft_split(buffer, '\n');
	if (!lines)
		return (free(buffer), NULL);
	return (free(buffer), lines);
}

int	is_rectangular(char **split)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(split[i]);
	while (split[i])
		if (ft_strlen(split[i++]) != len)
			return (FALSE);
	return (TRUE);
}
void	map_init(t_tab *map, char **split)
{
	map->tab = (void **)split;
	map->element_size = sizeof(char);
	map->rows = ft_split_len(split);
	map->cols = ft_strlen(split[0]);
}

void	parsing(t_tab *map, char *map_file)
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

void	validator_error_handler(t_tab *map)
{
	ft_split_free((char **)map->tab);
	ft_printf("Invalid Map\n");
	exit(1);
}

void	check_size(t_tab *map)
{
	if (map->rows < 3 || map->cols < 3)
		validator_error_handler(map);
}

int	valid_count(t_char_counter counter)
{
	if (counter.c_count < 1)
		return (FALSE);
	if (counter.e_count != 1 || counter.p_count != 1)
		return (FALSE);
	return (TRUE);
}

t_char_counter	check_chars(t_tab *map)
{
	t_char_counter	counter;
	size_t			i;

	counter.c_count = 0;
	counter.e_count = 0;
	counter.p_count = 0;
	i = 0;
	while (map->tab[i])
	{
		if (!ft_str_allinset((const char *)map->tab[i], VALID_CHARS))
			validator_error_handler(map);
		counter.c_count += ft_str_charcount((const char *)map->tab[i], 'C');
		counter.e_count += ft_str_charcount((const char *)map->tab[i], 'E');
		counter.p_count += ft_str_charcount((const char *)map->tab[i], 'P');
		i++;
	}
	if (!valid_count(counter))
		validator_error_handler(map);
	return (counter);
}
void	check_borders_row(t_tab *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (col < map->cols)
		if (((char **)map->tab)[row][col++] != '1')
			validator_error_handler(map);
	row = map->rows - 1;
	col = 0;
	while (col < map->cols)
		if (((char **)map->tab)[row][col++] != '1')
			validator_error_handler(map);
}

void check_borders_col(t_tab *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < map->rows)
		if (((char **)map->tab)[row++][col] != '1')
			validator_error_handler(map);
	row = 0;
	col = map->cols - 1;
	while (row < map->rows)
		if (((char **)map->tab)[row++][col] != '1')
			validator_error_handler(map);
}

int	path_solver(t_tab *dup, size_t row, size_t col, t_char_counter *reachable)
{
	if (((char**)dup->tab)[row][col] == 'E')
		reachable->e_count++;
	if (((char**)dup->tab)[row][col] == 'C')
		reachable->c_count++;
	if (((char**)dup->tab)[row][col] == '1')
		return (FALSE);
	((char**)dup->tab)[row][col] = '1';
	if (path_solver(dup, row - 1, col, reachable)
		|| path_solver(dup, row, col + 1, reachable)
		|| path_solver(dup, row + 1, col, reachable)
		|| path_solver(dup, row, col - 1, reachable))
		return (TRUE);
	return (FALSE);
}
void	get_start_player_pos(t_tab map, t_position* pos)
{
	size_t	row;
	size_t	col;
	
	row = 0;
	col = 0;
	while (row < map.rows)
	{	
		col = 0;
		while (col < map.cols)
		{
			if (((char **)map.tab)[row][col] == 'P')
				{
					pos->row = row;
					pos->col = col;
					return ;
				}
			col++;
		}
		row++;
	}
}

void	check_valid_path(t_tab *map, t_char_counter counter)
{
	t_tab			*dup;
	t_position		player_pos;
	t_char_counter	reachable;

	
	reachable.c_count = 0;
	reachable.e_count = 0;
	get_start_player_pos(*map, &player_pos);
	dup = ft_tab_dup(*map);
	if (!dup)
		validator_error_handler(map);
	path_solver(dup, player_pos.row, player_pos.col, &reachable);
	ft_tab_free(dup);
	if (reachable.c_count != counter.c_count
		|| reachable.e_count != counter.e_count)
		validator_error_handler(map);
}

void	validation(t_tab *map)
{
	t_char_counter	counter;

	check_size(map);
	check_borders_row(map);
	check_borders_col(map);
	counter = check_chars(map);
	check_valid_path(map, counter);
}


int	main(int argc, char **argv)
{
	t_tab map;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"));
	parsing(&map, argv[1]);
	validation(&map);
	ft_split_print((char **)map.tab);

	ft_split_free((char **)map.tab);
}


// check route
