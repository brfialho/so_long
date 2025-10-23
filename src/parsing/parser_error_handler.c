/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:55:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 17:55:20 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	parser_error_handler(int fd, char **split)
{
	if (fd)
		close(fd);
	if (split)
		ft_split_free(split);
	ft_printf("Error in parsing\n");
	exit(1);
}
