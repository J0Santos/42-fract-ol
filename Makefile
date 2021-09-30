NAME = fractol
SRCS = fractol.c
OBJS = $(SRCS:.c=.o)
FLAGS = -W -W -W -g
INCS = -Iincludes -Llibft -lft -Lmlx -lmlx
CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	cp ./mlx/libmlx.dylib ./
	$(CC) $(FLAGS) $(INCS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./libft
	rm -f libmlx.dylib

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C ./mlx
	$(MAKE) fclean -C ./libft
	rm -f libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
