/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:12:40 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 20:56:33 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static int	valid_count(t_chr_cnt counter);

void	check_chars(t_tab *map, t_chr_cnt *obj)
{
	size_t			i;

	obj->c_count = 0;
	obj->e_count = 0;
	obj->p_count = 0;
	obj->x_count = 0;
	i = 0;
	while (map->tab[i])
	{
		if (!ft_str_allinset((const char *)map->tab[i], VALID_CHARS))
			validator_error_handler(map, CHARS);
		obj->c_count += ft_str_charcount((const char *)map->tab[i], QUEST);
		obj->e_count += ft_str_charcount((const char *)map->tab[i], EXIT);
		obj->p_count += ft_str_charcount((const char *)map->tab[i], PLAYER);
		obj->x_count += ft_str_charcount((const char *)map->tab[i], MONSTER);
		i++;
	}
	if (!valid_count(*obj))
		validator_error_handler(map, COUNT);
}

static int	valid_count(t_chr_cnt obj)
{
	if (obj.c_count < 1
		|| obj.x_count < 1
		|| obj.e_count != 1
		|| obj.p_count != 1)
		return (FALSE);
	return (TRUE);
}
