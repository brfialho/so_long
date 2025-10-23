/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:12:40 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 18:43:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	valid_count(t_char_counter counter);

void	check_chars(t_tab *map, t_char_counter *counter)
{
	size_t			i;

	counter->c_count = 0;
	counter->e_count = 0;
	counter->p_count = 0;
	i = 0;
	while (map->tab[i])
	{
		if (!ft_str_allinset((const char *)map->tab[i], VALID_CHARS))
			validator_error_handler(map, CHARS);
		counter->c_count += ft_str_charcount((const char *)map->tab[i], 'C');
		counter->e_count += ft_str_charcount((const char *)map->tab[i], 'E');
		counter->p_count += ft_str_charcount((const char *)map->tab[i], 'P');
		i++;
	}
	if (!valid_count(*counter))
		validator_error_handler(map, COUNT);
}

static int	valid_count(t_char_counter counter)
{
	if (counter.c_count < 1)
		return (FALSE);
	if (counter.e_count != 1 || counter.p_count != 1)
		return (FALSE);
	return (TRUE);
}
