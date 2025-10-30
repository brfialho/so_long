/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:17:12 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/30 17:17:26 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	get_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((unsigned int)r << 16 | g << 8 | b);
}
