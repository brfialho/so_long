/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:55:43 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 20:10:18 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**read_lines(int fd)
{
	char	**lines;
	char	*buffer;
	char	*gnl;

	buffer = NULL;
	gnl = get_next_line(fd);
	if (!gnl)
		return (NULL);
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
