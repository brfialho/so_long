/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:39:13 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/31 17:40:49 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_usleep(long usec)
{
	struct	timeval start;
	struct	timeval	now;
	long			time_passed;
	
	time_passed = 0;
	gettimeofday(&start, NULL);
	while (time_passed < usec)
	{
		gettimeofday(&now, NULL);
		time_passed = (now.tv_sec - start.tv_sec) * 1000000 + now.tv_usec - start.tv_usec;
	}
}
