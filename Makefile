NAME		= server client

LIBFT 	= libft/libft.a

SRC		= client.c server.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I./libft
OFLAGS 	=   -Wall -Wextra -Werror -L./libft -lft

all:	$(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OFLAGS) $@.o -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	clean
	rm -rf $(OBJ) $(NAME)
	make -C libft fclean

re:	fclean all

.PHONY:all clean fclean re libft
