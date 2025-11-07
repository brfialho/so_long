/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_allinset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:26:55 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/22 20:38:50 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_allinset(const char *string, const char *set)
{
	const char	*s;

	s = string;
	while (*s)
		if (!ft_strchr(set, *s++))
			return (NULL);
	return ((char *)string);
}
