/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:14:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	obj_finder(t_tab map, t_pos *player, t_pos *exit);
static int	path_solver(t_tab *dup, size_t row, size_t col, t_chr_cnt *found);

void	check_valid_path(t_tab *map, t_chr_cnt obj, t_pos *player, t_pos *exit)
{
	t_tab		*dup;
	t_chr_cnt	found;

	found.c_count = 0;
	found.e_count = 0;
	obj_finder(*map, player, exit);
	dup = ft_tab_dup(*map);
	if (!dup)
		validator_error_handler(map, MEMORY);
	path_solver(dup, player->row, player->col, &found);
	ft_tab_free(dup);
	if (found.c_count != obj.c_count || !found.e_count)
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
			if (((char **)map.tab)[row][col] == PLAYER)
				*player = (t_pos){row, col};
			if (((char **)map.tab)[row][col] == EXIT)
				*exit = (t_pos){row, col};
			col++;
		}
		row++;
	}
}

static int	path_solver(t_tab *dup, size_t row, size_t col, t_chr_cnt *found)
{
	if (((char **)dup->tab)[row][col] == EXIT)
		found->e_count++;
	if (((char **)dup->tab)[row][col] == QUEST)
		found->c_count++;
	if (((char **)dup->tab)[row][col] == WALL)
		return (FALSE);
	((char **)dup->tab)[row][col] = WALL;
	if (path_solver(dup, row - 1, col, found)
		|| path_solver(dup, row, col + 1, found)
		|| path_solver(dup, row + 1, col, found)
		|| path_solver(dup, row, col - 1, found))
		return (TRUE);
	return (FALSE);
}
