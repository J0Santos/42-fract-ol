NAME = fractol
LIBFT =	./libft/libft.a
SRCS = fractol.c
OBJS = $(SRCS:.c=.o)
FLAGS = -W -W -W -g
INCS = -Iincludes -Llibft -lft -Imlx -lmlx
CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(INCS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
