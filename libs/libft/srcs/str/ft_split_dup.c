/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:27:23 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 12:45:22 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_dup(char **split)
{
	char	**new;
	size_t	len;

	len = ft_split_len(split);
	new = ft_calloc(len + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (len--)
	{
		new[len] = ft_strdup(split[len]);
		if (!new[len])
			return (ft_split_free(new), NULL);
	}
	return (new);
}
