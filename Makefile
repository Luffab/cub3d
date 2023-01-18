# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 00:41:35 by fatilly           #+#    #+#              #
#    Updated: 2021/05/24 15:49:54 by fatilly          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft.a

MINILIBX = libmlx.a

INCLUDES = include/

SRCS =	srcs/main.c \
		srcs/verify_parsing.c \
		srcs/parsing_arg_utils3.c \
		srcs/parsing_arg_utils2.c \
		srcs/parsing_arg_utils.c \
		srcs/parsing_arg.c \
		srcs/parsing_map_utils.c \
		srcs/parsing_map_utils2.c \
		srcs/parsing_map.c \
		srcs/init_raycast.c \
		srcs/wall_casting.c \
		srcs/texture_utils.c \
		srcs/character.c \
		srcs/character2.c \
		srcs/sprite.c \
		srcs/sprite_utils.c \
		srcs/texture.c \
		srcs/bmp.c \
		srcs/texture2.c

FLAGS = -Wall -Wextra -Werror -g2

HEADER_FILE = ./include

HEADERS =	$(HEADER_FILE)/cub3d.h \
			./libft/libft.h

LIB_NAME = libft/libft.a

MLX_NAME = mlx/libmlx.a

OBJS = ${SRCS:.c=.o}

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re

$(NAME): $(OBJS) $(LIB_NAME) $(MLX_NAME)
	clang $(OBJS) $(LIB_NAME) $(MLX_NAME) -o $(NAME) -lm -framework OpenGL -framework AppKit

$(OBJS): %.o: %.c $(HEADERS)
	clang $(FLAGS) -I$(HEADER_FILE) -c $< -o $@

$(LIB_NAME):
	$(MAKE) -C libft

$(MLX_NAME):
	$(MAKE) -C mlx

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C mlx clean
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all
