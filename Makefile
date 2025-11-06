CC = cc -Werror -Wextra -Wall

MLX_INCLUDES = -Imlx/

LIBFT_INCLUDES = -Ilibft/headers/

SOLONG_INCLUDES = -Iincludes/

DEPENDENCIES = -lXext -lX11 -lm -lz

# SRC = minilib_learning.c

SRC = src/main.c \
		src/parsing/is_rectangular.c \
		src/parsing/map_init.c \
		src/parsing/parser_error_handler.c \
		src/parsing/map_parser.c \
		src/parsing/read_lines.c \
		src/parsing/valid_file_name.c \
		src/validation/check_borders_col.c \
		src/validation/check_borders_row.c \
		src/validation/check_chars.c \
		src/validation/check_size.c \
		src/validation/check_valid_path.c \
		src/validation/validator_error_handler.c \
		src/validation/map_validator.c \
		src/game/display/draw_square.c \
		src/game/display/get_rgb.c \
		src/game/display/pixel_put.c \
		src/game/display/render_image.c \
		src/game/init_destroy/destroy_game.c \
		src/game/init_destroy/destroy_mlx.c \
		src/game/init_destroy/init_game.c \
		src/game/init_destroy/init_mlx_display.c \
		src/game/keys/all_key_release.c \
		src/game/keys/handle_keys.c \
		src/game/keys/key_press.c \
		src/game/logic/move_player.c \
		src/game/game_loop.c \
		src/game/utils.c

BONUS_SRC = src_bonus/main.c \
		src_bonus/parsing/is_rectangular.c \
		src_bonus/parsing/map_init.c \
		src_bonus/parsing/parser_error_handler.c \
		src_bonus/parsing/map_parser.c \
		src_bonus/parsing/read_lines.c \
		src_bonus/parsing/valid_file_name.c \
		src_bonus/validation/check_borders_col.c \
		src_bonus/validation/check_borders_row.c \
		src_bonus/validation/check_chars.c \
		src_bonus/validation/check_size.c \
		src_bonus/validation/check_valid_path.c \
		src_bonus/validation/validator_error_handler.c \
		src_bonus/validation/map_validator.c \
		src_bonus/game/display/display_moves.c \
		src_bonus/game/display/render_image.c \
		src_bonus/game/init_destroy/destroy.c \
		src_bonus/game/init_destroy/init_game.c \
		src_bonus/game/init_destroy/init_mlx_display.c \
		src_bonus/game/init_destroy/init_img.c \
		src_bonus/game/keys/all_key_release.c \
		src_bonus/game/keys/handle_keys.c \
		src_bonus/game/keys/key_press.c \
		src_bonus/game/logic/count_frame.c \
		src_bonus/game/logic/game_over.c \
		src_bonus/game/logic/handle_monsters.c \
		src_bonus/game/logic/move_monster.c \
		src_bonus/game/logic/move_player.c \
		src_bonus/game/game_loop.c \
		src_bonus/game/utils.c

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
	SRC = $(BONUS_SRC)
endif

O_DIR = obj/
OBJ = $(SRC:%.c=$(O_DIR)%.o)

LIBPATH = libft/
LIBFT= $(LIBPATH)libft.a

LIBMLX_PATH = mlx/
LIBMLX = $(LIBMLX_PATH)libmlx_Linux.a

NAME = so_long

all: $(LIBFT) $(LIBMLX) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(LIBMLX) $(DEPENDENCIES) -o $(NAME)
	@echo -n "\033[32m\nSuccessfully Generated \033[0mSo Long \n\n"

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
	@sleep 0.0001
	@$(CC) $(MLX_INCLUDES) $(LIBFT_INCLUDES) $(SOLONG_INCLUDES) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBPATH)

$(LIBMLX):
	@make --no-print-directory -C $(LIBMLX_PATH)

clean:
	@echo "\033[95mCleansing So Long Objects"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@make --no-print-directory -C $(LIBPATH) clean
	@make --no-print-directory -C $(LIBMLX_PATH) clean
	@rm -rf $(O_DIR)

fclean:
	@echo "\033[95mCleansing So Long"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@make --no-print-directory -C $(LIBPATH) fclean
	@make --no-print-directory -C $(LIBMLX_PATH) clean
	@rm -rf $(O_DIR)
	@rm -f $(NAME)

re: fclean all

bonus: all

rebonus: fclean bonus

.PHONY: $(LIBFT) re fclean clean