NAME = fdf

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a

RM = rm -f

SRC = main.c print_fdf.c bressen.c

OBJS = ${SRC:.c=.o}
#Hay que añadir los includes como dependencias
$(NAME): $(OBJS)
		@make -C $(LIBFTDIR)
		#$(CC) -o $(NAME) $(MLXFLAGS) -fsanitize=address $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) $(MLX) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	#$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re
