/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:00:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/07 17:07:20 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_min(int *array, size_t len)
{
	size_t	i;
	int		tmp;

	tmp = INT_MAX;
	i = 0;
	while (i < len)
	{
		if (array[i] < tmp)
			tmp = array[i];
		i++;
	}
	return (tmp);
}
