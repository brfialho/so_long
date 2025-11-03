/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:55:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 20:37:10 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	parser_error_handler(int fd, char **split, t_error error)
{
	if (fd)
		close(fd);
	if (split)
		ft_split_free(split);
	if (error == MEMORY)
		ft_printf("Error\nNot enough memory\n");
	if (error == USAGE)
		ft_printf("Error\nUsage: ./so_long <map_file.ber>\n");
	if (error == NAME)
		ft_printf("Error\nInvalid file name\n");
	if (error == READ)
		ft_printf("Error\nCould not read file\n");
	if (error == EMPTY)
		ft_printf("Error\nInvalid Map : empty file\n");
	if (error == RECTANGULAR)
		ft_printf("Error\nInvalid Map : not valid a matrix\n");
	exit(1);
}
