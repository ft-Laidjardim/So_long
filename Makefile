# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 15:30:28 by ljessica          #+#    #+#              #
#    Updated: 2025/09/08 15:38:08 by ljessica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = ./srcs

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

MLIBX = ./minilibx-linux/libmlx.a
MLIBX_DIR = ./minilibx-linux

SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/check_args.c \
		$(SRCS_DIR)/map_is_valid.c \
		$(SRCS_DIR)/inits.c \
		$(SRCS_DIR)/init_map_utils.c \
		$(SRCS_DIR)/hook_functions.c \
		$(SRCS_DIR)/press_left.c \
		$(SRCS_DIR)/press_right.c \
		$(SRCS_DIR)/press_up.c \
		$(SRCS_DIR)/press_down.c \
		$(SRCS_DIR)/free_functions.c \
		$(SRCS_DIR)/render.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm 

RM = rm -f
all: $(NAME)

$(NAME): $(LIBFT) $(MLIBX) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(MLIBX):
	$(MAKE) -C $(MLIBX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLIBX_DIR)

fclean: clean
	$(RM) $(NAME) $(B_NAME) $(LIBFT) $(MLIBX)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) all

norminette:
	norminette ./srcs
	norminette ./include
	norminette ./libft
.PHONY: all clean fclean re norminette
