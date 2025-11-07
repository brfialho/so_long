/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_monsters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:36:14 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/07 18:11:32 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static t_pos_move	get_ramdom_move(t_pos next);
static t_pos_move	get_follow_move(t_game *game, t_pos next);
static int			calc_path_costs(int **map, int row, int col, int steps);
static void			prepare_matrix(char **map, int **tab);

void	handle_monsters(t_game *game)
{
	static int	cooldown = 0;
	int			i;

	if (++cooldown > SPEED)
		cooldown = 1;
	i = -1;
	while (++i < (int)game->obj.x_count)
	{
		if (game->monster[i].type == MONSTER && !(cooldown % (SPEED / 4)))
			move_monster(game, get_ramdom_move(game->monster[i].pos), i);
		else if (game->monster[i].type == CRAZY && !(cooldown % (SPEED / 10)))
			move_monster(game, get_follow_move(game, game->monster[i].pos), i);
	}
}

static t_pos_move	get_ramdom_move(t_pos next)
{
	int	min;
	int	max;
	int	ramdom;

	min = 1;
	max = 4;
	ramdom = (rand() % (max - min + 1)) + min;
	if (ramdom == 1)
		return ((t_pos_move){next.row - 1, next.col, UP});
	if (ramdom == 2)
		return ((t_pos_move){next.row, next.col + 1, RIGHT});
	if (ramdom == 3)
		return ((t_pos_move){next.row + 1, next.col, DOWN});
	return ((t_pos_move){next.row, next.col - 1, LEFT});
}

static t_pos_move	get_follow_move(t_game *game, t_pos next)
{
	t_tab	tab;
	int		cheapest;
	int		move[4];

	ft_tab_init_alloc(&tab, game->map.rows, game->map.cols, sizeof(int));
	if (!tab.tab && printf ("\nInsuficient Memory\n"))
		destroy_game(game);
	prepare_matrix(((char **)game->map.tab), ((int **)tab.tab));
	((int **)tab.tab)[next.row][next.col] = -10;
	calc_path_costs(((int **)tab.tab), \
						game->player.row, game->player.col, 1);
	move[0] = ((int **)tab.tab)[next.row - 1][next.col];
	move[1] = ((int **)tab.tab)[next.row][next.col + 1];
	move[2] = ((int **)tab.tab)[next.row + 1][next.col];
	move[3] = ((int **)tab.tab)[next.row][next.col - 1];
	ft_tab_free_content(&tab);
	cheapest = get_cheapest(move);
	if (move[0] == cheapest)
		return ((t_pos_move){next.row - 1, next.col, UP});
	else if (move[1] == cheapest)
		return ((t_pos_move){next.row, next.col + 1, RIGHT});
	else if (move[2] == cheapest)
		return ((t_pos_move){next.row + 1, next.col, DOWN});
	else
		return ((t_pos_move){next.row, next.col - 1, LEFT});
}

static void	prepare_matrix(char **map, int **tab)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("1AXDZVB", map[i][j]))
				tab[i][j] = -1;
			if (ft_strchr("CEP0", map[i][j]))
				tab[i][j] = 0;
		}
	}
}

static int	calc_path_costs(int **map, int row, int col, int steps)
{
	if (map[row][col] != 0)
		return (FALSE);
	map[row][col] = steps++;
	if (calc_path_costs(map, row - 1, col, steps)
		|| calc_path_costs(map, row, col + 1, steps)
		|| calc_path_costs(map, row + 1, col, steps)
		|| calc_path_costs(map, row, col - 1, steps))
		return (TRUE);
	return (FALSE);
}
