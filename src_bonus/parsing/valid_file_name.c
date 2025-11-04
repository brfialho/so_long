/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:54:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	valid_file_name(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(s + len - 4, ".ber", 4))
		return (FALSE);
	len -= 4;
	while (len)
		if (s[len-- - 1] == '.')
			return (FALSE);
	return (TRUE);
}
