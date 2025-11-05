/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:12:58 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/05 20:53:54 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

// Includes
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

// Macros
# ifndef VALID_CHARS
#  define VALID_CHARS "01CEPX"
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

# ifndef ENEMY
#  define ENEMY 'X'
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

# ifndef SPEED
#  define SPEED 40
# endif

# ifndef TEXTURES
#  define TEXTURES 12
# endif

# ifndef FRAME_MAX
#  define FRAME_MAX 200
# endif

typedef enum e_error
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
}	t_error;

typedef enum e_direction
{
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4
}	t_direction;

typedef enum e_texture
{
	E,
	F,
	W,
	Q,
	Q_U,
	Q_D,
	M,
	M_L,
	M_R,
	P,
	P_L,
	P_R
}	t_texture;

// Structs
typedef struct s_chr_cnt
{
	size_t	c_count;
	size_t	e_count;
	size_t	p_count;
	size_t	x_count;
}	t_chr_cnt;

typedef struct s_pos
{
	size_t	row;
	size_t	col;
}	t_pos;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img[TEXTURES];
	int			total_height;
	int			total_width;
	int			img_height;
	int			img_width;
	int			key_is_pressed[ASCII];
}	t_mlx;

typedef struct s_monster
{
	t_pos	pos;
	int		quest_eaten;
}	t_monster;

typedef struct s_game
{
	t_tab		map;
	t_mlx		mlx;
	t_pos		player;
	t_pos		exit;
	t_chr_cnt	obj;
	t_monster	*monster;
	int			frame;
	int			moves;
}	t_game;

//Functions

// Map parsing
int		is_rectangular(char **split);
void	map_init(t_tab *map, char **split);
void	parser_error_handler(int fd, char **split, t_error error);
void	map_parser(t_tab *map, int argc, char **argv);
char	**read_lines(int fd);
int		valid_file_name(char *s);

// Map validation
void	check_borders_col(t_tab *map);
void	check_borders_row(t_tab *map);
void	check_chars(t_tab *map, t_chr_cnt *obj);
void	check_size(t_tab *map);
void	check_valid_path(t_tab *map, t_chr_cnt obj, t_pos *player, t_pos *exit);
void	validator_error_handler(t_tab *map, t_error error);
void	map_validator(t_game *game);

// Game
int		game_loop(t_game *game);

// Init / Destroy
int		destroy_game(t_game *game);
void	destroy_img(t_mlx *mlx);
void	destroy_mlx(t_mlx *mlx);
void	init_game(t_game *game);
int		init_img(t_mlx *mlx);
int		init_mlx_display(t_mlx *mlx);

// Display
void	display_moves(t_game *game);
t_uint	get_rgb(t_uchar r, t_uchar g, t_uchar b);
void	render_image(t_game *game);

// Keys
void	all_key_release(t_game *game);
void	handle_keys(t_game *game);
int		key_press(int keycode, t_game *game);

// Logic
void	handle_monsters(t_game *game);
void	move_player(t_game *game, t_pos next_pos);
void	move_monster(t_game *game, t_pos next_pos, int i);

// Utils
void	ft_usleep(long usec);
int		pos_cmp(t_pos first, t_pos second);

#endif