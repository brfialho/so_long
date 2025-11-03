/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:12:58 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 19:37:58 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
 #define MAIN_H

// Macros
# ifndef VALID_CHARS
#  define VALID_CHARS "01CEP"
# endif

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef EXIT
#  define EXIT 'E'
# endif

# ifndef QUEST
#  define QUEST 'C'
# endif

# ifndef FLOOR
#  define FLOOR '0'
# endif

# ifndef WALL
#  define WALL '1'
# endif

# ifndef ASCII
#  define ASCII 256
# endif

# ifndef ESC
#  define ESC 27
# endif

# ifndef SQUARE
#  define SQUARE 32
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

typedef enum
{
	UP,
	RIGHT,
	DOWN,
	LEFT
} e_direction;

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

typedef struct s_pos
{
	size_t	row;
	size_t	col;
}	t_pos;

typedef struct	s_mlx_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_mlx_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	img;
	int			height;
	int			width;
	int			key_is_pressed[ASCII];
}				t_mlx;

typedef struct s_game
{
	t_tab			map;
	t_mlx			mlx;
	t_pos			player;
	t_pos			exit;
	t_char_counter	obj;
	size_t			moves;
}				t_game;

//Functions

// Map parsing
int		is_rectangular(char **split);
void	map_init(t_tab *map, char **split);
void	parser_error_handler(int fd, char **split, e_error error);
void	map_parser(t_tab *map, int argc, char **argv);
char	**read_lines(int fd);
int		valid_file_name(char *s);

// Map validation
void	check_borders_col(t_tab *map);
void	check_borders_row(t_tab *map);
void	check_chars(t_tab *map, t_char_counter *obj);
void	check_size(t_tab *map);
void	check_valid_path(t_tab *map, t_char_counter obj, t_pos *player, t_pos *exit);
void	validator_error_handler(t_tab *map, e_error error);
void	map_validator(t_game *game);

// Game
int		game_loop(t_game *game);

// Init / Destroy
int				destroy_game(t_game *game);
int				destroy_mlx(t_mlx *mlx, int win, int img);
void			init_game(t_game *game);
int				init_mlx_display(t_mlx *mlx);

// Display
void	draw_square(t_mlx mlx, int row, int col, u_int color);
u_int	get_rgb(u_char r, u_char g, u_char b);
void	pixel_put(t_mlx_img *img, int x, int y, unsigned int color);
int		render_image(t_game *game);

// Keys
void	all_key_release(t_game *game);
void	handle_keys(t_game *game);
int		key_press(int keycode, t_game *game);

// Logic
void	move_player(t_game *game, t_pos next_pos);

// Utils
void	ft_usleep(long usec);

#endif