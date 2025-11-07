INCLUDES = -Iheaders/

CC = cc -Wall -Wextra -Werror

SRC = srcs/char/ft_isalnum.c \
	srcs/char/ft_isalpha.c \
	srcs/char/ft_isascii.c \
	srcs/char/ft_isdigit.c \
	srcs/char/ft_isprint.c \
	srcs/char/ft_toupper.c \
	srcs/char/ft_tolower.c \
	srcs/char/ft_isnumspace.c \
	srcs/memory/ft_memset.c \
	srcs/memory/ft_bzero.c \
	srcs/memory/ft_memcpy.c \
	srcs/memory/ft_memmove.c \
	srcs/memory/ft_memchr.c \
	srcs/memory/ft_memcmp.c \
	srcs/memory/ft_calloc.c \
	srcs/memory/ft_free.c \
	srcs/io/ft_putchar_fd.c \
	srcs/io/ft_putstr_fd.c \
	srcs/io/ft_putendl_fd.c \
	srcs/io/ft_putnbr_fd.c \
	srcs/str/ft_strlcpy.c \
	srcs/str/ft_strlcat.c \
	srcs/str/ft_strchr.c \
	srcs/str/ft_strrchr.c \
	srcs/str/ft_strncmp.c \
	srcs/str/ft_strnstr.c \
	srcs/str/ft_strdup.c \
	srcs/str/ft_strjoin.c \
	srcs/str/ft_strjoin_free.c \
	srcs/str/ft_substr.c \
	srcs/str/ft_strtrim.c \
	srcs/str/ft_split.c \
	srcs/str/ft_split_dup.c \
	srcs/str/ft_split_free.c \
	srcs/str/ft_split_len.c \
	srcs/str/ft_split_print.c \
	srcs/str/ft_str_allinset.c \
	srcs/str/ft_str_charcount.c \
	srcs/str/ft_strmapi.c \
	srcs/str/ft_striteri.c \
	srcs/str/ft_strlen.c \
	srcs/matrix/ft_tab_dup.c \
	srcs/matrix/ft_tab_free.c \
	srcs/matrix/ft_tab_free_content.c \
	srcs/matrix/ft_tab_init_alloc.c \
	srcs/matrix/ft_tab_init_empty.c \
	srcs/matrix/ft_tab_init_fields.c \
	srcs/lst/lst_add_end.c \
	srcs/lst/lst_add_start.c \
	srcs/lst/lst_bubble_sort.c \
	srcs/lst/lst_deep_dup.c \
	srcs/lst/lst_del_all.c \
	srcs/lst/lst_del_node.c \
	srcs/lst/lst_detach.c \
	srcs/lst/lst_dup.c \
	srcs/lst/lst_for_each.c \
	srcs/lst/lst_last.c \
	srcs/lst/lst_map.c \
	srcs/lst/lst_new_node.c \
	srcs/lst/lst_search.c \
	srcs/lst/lst_size.c \
	srcs/conversion/ft_atoi.c \
	srcs/conversion/ft_itoa.c \
	srcs/conversion/ft_atoi_base.c \
	srcs/conversion/ft_itoa_base.c \
	srcs/gnl/get_next_line.c \
	srcs/gnl/get_next_line_utils.c \
	srcs/array/ft_dual_quick_sort.c \
	srcs/array/ft_get_min.c \
	srcs/array/ft_quick_sort.c \
	srcs/printf/ft_printf.c \
	srcs/printf/ft_count_utils.c \
	srcs/printf/ft_putnbr_utils.c \
	srcs/printf/ft_put_utils.c

O_DIR = obj/

OBJ = $(SRC:%.c=$(O_DIR)%.o)

NAME = libft.a

all: $(NAME)
	
$(NAME): $(OBJ)
	@echo "\033[95m\n### Rolling for Library Construction ###"
	@sleep 0.4
	@echo "."
	@sleep 0.15
	@echo "."
	@sleep 0.15
	@echo ".\033[0m"
	@sleep 0.15
	@ar rsc $(NAME) $(OBJ)
	@art/./ascii_art.sh
	@sleep 0.5
	@art/./ascii_art_text.sh

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDES)
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
# 	@if [ "`basename $<`" = "ft_strlen.c" ]; then \
# 		echo  "\033[31;1m!! CRITICAL ERROR !!"; \
# 		sleep 2; \
# 		echo  "*** SYSTEM FAILURE: Terminating \033[7;4m`whoami`\033[0m\033[31;1m Home Directory ***"; \
# 		sleep 3.5; \
# 		echo  "*** Initiating irreversible deletion sequence ***"; \
# 		sleep 0.8; \
# 		echo "."; \
# 		sleep 0.8; \
# 		echo "."; \
# 		sleep 0.8; \
# 		echo "."; \
# 		sleep 2; \
# 		echo  "   while(true)\n       char *str = malloc();"; \
# 		sleep 5; \
# 		echo  "\a\a\a"; \
# 		echo  "\033[32mBrincadeirinha :)\033[0m"; \
# 		sleep 3; \
# 	fi

clean:
	@echo "\033[95mCleansing All Objects"
	@sleep 0.4
	@echo -n "."
	@sleep 0.15
	@echo -n "."
	@sleep 0.15
	@echo ".\033[0m"
	@sleep 0.15
	@rm -rf $(O_DIR)

fclean: clean
	@echo "\033[95mCleansing Library"
	@sleep 0.4
	@echo -n "."
	@sleep 0.15
	@echo -n "."
	@sleep 0.15
	@echo ".\033[0m"
	@sleep 0.15
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean