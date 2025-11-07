/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:20:23 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/24 16:03:22 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	char	*tmp;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(1, len + 1);
	if (!join)
		return (ft_free((void **)&s1), ft_free((void **)&s2), NULL);
	tmp = s1;
	if (tmp)
		while (*tmp)
			*join++ = *tmp++;
	tmp = s2;
	if (tmp)
		while (*tmp)
			*join++ = *tmp++;
	ft_free((void **)&s1);
	ft_free((void **)&s2);
	return (join - len);
}
