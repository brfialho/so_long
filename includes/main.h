/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:12:58 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/29 20:02:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
 #define MAIN_H

// Macros
# ifndef VALID_CHARS
#  define VALID_CHARS "01CEP"
# endif

# ifndef WIDTH 
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef ESC
#  define ESC 27
# endif

# ifndef ASCII
#  define ASCII 256
# endif

typedef enum
{
	MEMORY,
	USAGE,
	NAME,
	READ,
	EMPTY,
	RECTANGULAR,
	SIZE,
	BORDER,
	CHARS,
	COUNT,
	PATH
} e_error;


// Includes
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

// Structs
typedef struct s_char_counter
{
	size_t	c_count;
	size_t	e_count;
	size_t	p_count;
}	t_char_counter;

typedef struct s_position
{
	size_t	row;
	size_t	col;
}	t_position;

//Functions

// Map parsing
int		is_rectangular(char **split);
void	map_init(t_tab *map, char **split);
void	parser_error_handler(int fd, char **split, e_error error);
void	parser(t_tab *map, int argc, char **argv);
char	**read_lines(int fd);
int		valid_file_name(char *s);

// Map validation

void	check_borders_col(t_tab *map);
void	check_borders_row(t_tab *map);
void	check_chars(t_tab *map, t_char_counter *counter);
void	check_size(t_tab *map);
void	check_valid_path(t_tab *map, t_char_counter counter);
void	validator_error_handler(t_tab *map, e_error error);
void	validator(t_tab *map);

#endif