# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 09:06:46 by ljessica          #+#    #+#              #
#    Updated: 2025/07/24 10:46:53 by ljessica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name

NAME = push_swap

# Compiler

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# files

SRCS = main.c fill.c push.c reverse_rotate.c split.c error_free.c order.c rotate.c swap.c sort.c sort_functions.c

OBJS = $(SRCS:.c=.o)

# Commands

RM = rm -fr

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) 

$(OBJS):%.o: %.c
	$(CC) $(CFLAGS) $< -c

test: all
	$(CC) $(CFLAGS) main.c -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re