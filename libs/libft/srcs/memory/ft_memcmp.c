/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:42:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 20:00:12 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- && *(char *)s1++ == *(char *)s2++)
		;
	return ((t_uchar) *(char *)--s1 - (t_uchar) *(char *)--s2);
}

// "hello\0"
// "hello\0"
// n 100