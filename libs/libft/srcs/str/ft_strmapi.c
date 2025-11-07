/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:36:12 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 19:57:33 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(t_uint, char))
{
	int		i;
	char	*new;

	i = -1;
	new = ft_calloc(ft_strlen(s) + 1, 1);
	if (!new)
		return (0);
	while (s[++i])
		new[i] = f((t_uint)i, s[i]);
	return (new);
}
