/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:48:22 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 19:58:14 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (ft_strlen((char *)s) + 1);
	while (len--)
		if ((t_uchar)c == s[len])
			return ((char *)s + len);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("abcdedf", 'a'));
// }