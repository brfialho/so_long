/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:26:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 12:18:05 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_split_len(char **split)
{
	size_t	len;

	len = 0;
	if (!split)
		return (0);
	while (split[len])
		len++;
	return (len);
}
