# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 22:22:31 by fmoran-m          #+#    #+#              #
#    Updated: 2024/02/01 22:23:57 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a

RM = rm -f

SRC = main.c print_fdf.c bressen.c rows_counter.c read_node.c get_map_line.c draw_map.c transformation.c inputs.c free_functions.c free_functions_2.c free_matrix.c file_checker.c init_functions.c read_map.c fdf_utils.c get_color.c

OBJS = ${SRC:.c=.o}
#Hay que añadir los includes como dependencias
$(NAME): $(OBJS)
		@make -C $(LIBFTDIR)
		$(CC) -o $(NAME) $(MLXFLAGS) -fsanitize=address $(OBJS) $(LIBFT)
		#$(CC) $(OBJS) $(LIBFT) $(MLX) -fsanitize=address -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
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
