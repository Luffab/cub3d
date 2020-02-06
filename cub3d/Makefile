NAME = cub3d
SRCS =	srcs/main.c \
		srcs/cub3d.c \
		srcs/ft_initcub.c \
		srcs/ft_parsing_arg.c \
		srcs/ft_parsing_map.c
HEADER = cub3d.h
OBJS = ${SRCS:.c=.o}

all: $(NAME)

libft/libft.a:
	make -C ./libft

minilibx/libmlx.a:
	make -C ./minilibx

$(NAME): $(SRCS) libft/libft.a minilibx/libmlx.a
	gcc -Wall -Wextra -Werror -L minilibx -lmlx -framework OpenGL -framework AppKit $(SRCS) libft/libft.a minilibx/libmlx.a -I include -o cub3d
clean:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)
fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./minilibx clean
	rm -f $(NAME)
re: fclean all