/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:39:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/07 17:16:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	ft_usleep(long usec)
{
	struct timeval	start;
	struct timeval	now;
	long			time_passed;

	time_passed = 0;
	gettimeofday(&start, NULL);
	while (time_passed < usec)
	{
		gettimeofday(&now, NULL);
		time_passed = (now.tv_sec - start.tv_sec) * 1000000 \
						+ now.tv_usec - start.tv_usec;
	}
}

int	pos_cmp(t_pos first, t_pos second)
{
	return (first.row == second.row && first.col == second.col);
}

int	get_cheapest(int *moves)
{
	int	tmp;
	int	i;

	tmp = INT_MAX;
	i = -1;
	while (++i < 4)
		if (moves[i] > 0 && moves[i] < tmp)
			tmp = moves[i];
	if (tmp == INT_MIN)
		return (-1);
	return (tmp);
}
