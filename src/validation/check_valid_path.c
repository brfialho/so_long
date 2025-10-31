/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:14:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/30 21:06:15 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	obj_finder(t_tab map, t_pos *player, t_pos *exit);
static int	path_solver(t_tab *dup, size_t row, size_t col, t_char_counter *reachable);

void	check_valid_path(t_tab *map, t_char_counter obj, t_pos *player, t_pos *exit)
{
	t_tab			*dup;
	t_char_counter	reachable;

	reachable.c_count = 0;
	reachable.e_count = 0;
	obj_finder(*map, player, exit);
	dup = ft_tab_dup(*map);
	if (!dup)
		validator_error_handler(map, MEMORY);
	path_solver(dup, player->row, player->col, &reachable);
	ft_tab_free(dup);
	if (reachable.c_count != obj.c_count || !reachable.e_count)
		validator_error_handler(map, PATH);
}

static void	obj_finder(t_tab map, t_pos *player, t_pos *exit)
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
				*player = (t_pos){row, col};
			if (((char **)map.tab)[row][col] == 'E')
				*exit = (t_pos){row, col};
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
