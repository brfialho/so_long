CC = cc -Werror -Wextra -Wall

MLX_INCLUDES = -Imlx/

LIBFT_INCLUDES = -Ilibft/headers/

SOLONG_INCLUDES = -Iincludes/

DEPENDENCIES = -lXext -lX11 -lm -lz

SRC = src/main.c \
		src/parsing/is_rectangular.c \
		src/parsing/map_init.c \
		src/parsing/parser_error_handler.c \
		src/parsing/parser.c \
		src/parsing/read_lines.c \
		src/parsing/valid_file_name.c 

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

.PHONY: $(LIBFT) re fclean clean