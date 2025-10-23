/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:57:08 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 17:57:16 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
