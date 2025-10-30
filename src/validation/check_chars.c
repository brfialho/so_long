/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:12:40 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/30 20:06:26 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	valid_count(t_char_counter counter);

void	check_chars(t_tab *map, t_char_counter *obj)
{
	size_t			i;

	obj->c_count = 0;
	obj->e_count = 0;
	obj->p_count = 0;
	i = 0;
	while (map->tab[i])
	{
		if (!ft_str_allinset((const char *)map->tab[i], VALID_CHARS))
			validator_error_handler(map, CHARS);
		obj->c_count += ft_str_charcount((const char *)map->tab[i], 'C');
		obj->e_count += ft_str_charcount((const char *)map->tab[i], 'E');
		obj->p_count += ft_str_charcount((const char *)map->tab[i], 'P');
		i++;
	}
	if (!valid_count(*obj))
		validator_error_handler(map, COUNT);
}

static int	valid_count(t_char_counter obj)
{
	if (obj.c_count < 1)
		return (FALSE);
	if (obj.e_count != 1 || obj.p_count != 1)
		return (FALSE);
	return (TRUE);
}
