NAME = fdf

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRC = main.c

OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
		@make -C $(LIBFTDIR)
		$(CC) -o $(NAME) $(MLXFLAGS) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re
