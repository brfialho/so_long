/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:14:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 19:17:29 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	player_finder(t_tab map, t_position *pos);
static int	path_solver(t_tab *dup, size_t row, size_t col, t_char_counter *reachable);

void	check_valid_path(t_tab *map, t_char_counter counter)
{
	t_tab			*dup;
	t_position		player_pos;
	t_char_counter	reachable;

	reachable.c_count = 0;
	reachable.e_count = 0;
	player_finder(*map, &player_pos);
	dup = ft_tab_dup(*map);
	if (!dup)
		validator_error_handler(map, MEMORY);
	path_solver(dup, player_pos.row, player_pos.col, &reachable);
	ft_tab_free(dup);
	if (reachable.c_count != counter.c_count || !reachable.e_count)
		validator_error_handler(map, PATH);
}

static void	player_finder(t_tab map, t_position *pos)
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

static int	path_solver(t_tab *dup, size_t row, size_t col, t_char_counter *reachable)
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
