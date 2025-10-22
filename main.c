/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:38 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/22 18:46:59 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (ft_printf("Error\n"));

// 	int fd = open(argv[1], O_RDONLY);

// 	if (fd < 0)
// 		return (ft_printf("Error : %s\n", strerror(errno)));

// 	t_tab	map;
// 	if (!ft_tab_innit_empty(&map, 5, 15, sizeof(char)))
// 		return (1);
// 	int i = -1;
// 	while ((map.tab[++i] = get_next_line(fd)))
// 		;
// 	for (int j = 0; j < i; j++)
// 		ft_printf("LINE: %d LEN: %s", ft_strlen(map.tab[j]), map.tab[j]);
// 	ft_tab_free_content(&map);
// }

void	parser_error_handler(int fd, char **split)
{
	if (fd)
		close(fd);
	if (split)
		ft_split_free(split);
	ft_printf("Error in parsing\n");
	exit(1);
}

int	valid_file_name(char *s)
{
	size_t len;

	len = ft_strlen(s);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(s + len - 4, ".ber", 4))
		return (FALSE);
	len -= 4;
	while (len)
		if (s[len-- - 1] == '.')
			return (FALSE);
	return(TRUE);
}

char	**read_lines(int fd)
{
	char	**lines;
	char	*buffer;
	char	*gnl;

	buffer = NULL;
	gnl = get_next_line(fd);
	while (gnl)
	{
		buffer = ft_strjoin_free(buffer, gnl);
		if (!buffer)
			return (NULL);
		gnl = get_next_line(fd);
	}
	lines = ft_split(buffer, '\n');
	if (!lines)
		return (free(buffer), NULL);
	return (free(buffer), lines);
}

int	is_rectangular(char **split)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(split[i]);
	while (split[i])
		if (ft_strlen(split[i++]) != len)
			return (FALSE);
	return (TRUE);
}
void	map_init(t_tab *map, char **split)
{
	map->tab = (void **)split;
	map->element_size = sizeof(char);
	map->rows = ft_split_len(split);
	map->cols = ft_strlen(split[0]);
}

void	parsing(t_tab *map, char *map_file)
{
	int		fd;
	char	**lines;

	if (!valid_file_name(map_file))
		parser_error_handler(0, NULL);
	fd = open(map_file, O_RDONLY);	
	if (fd == -1)
		parser_error_handler(0, NULL);
	lines = read_lines(fd);
	if (!lines)
		parser_error_handler(fd, NULL);
	if (!is_rectangular(lines))
		parser_error_handler(fd, lines);
	map_init(map, lines);
	close(fd);
}


int	main(int argc, char **argv)
{
	t_tab map;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"));

	parsing(&map, argv[1]);
	ft_split_print((char **)map.tab);

	
	ft_split_free((char **)map.tab);
}



// check rectangular
// check chars
// check borders
// check number of exit, start, collect
// check route
