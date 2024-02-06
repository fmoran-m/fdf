# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 22:22:31 by fmoran-m          #+#    #+#              #
#    Updated: 2024/02/02 01:28:18 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = fdf.h

MLX = ./mlx/libmlx.a

RM = rm -f

STD = inputs.c main.c transformation.c

STD_OBJS = ${STD:.c=.o}

SRC = print_fdf.c bressen.c rows_counter.c read_node.c get_map_line.c draw_map.c free_functions.c free_functions_2.c free_matrix.c file_checker.c init_functions.c read_map.c fdf_utils.c get_color.c get_color_utils.c

OBJS = ${SRC:.c=.o}

BONUS = main_bonus.c transformation_bonus.c inputs_bonus.c control_init_bonus.c rotation_bonus.c mouse_functions_bonus.c key_input_bonus.c

BONUS_OBJS = ${BONUS:.c=.o}

$(NAME): $(STD_OBJS) $(OBJS) $(HEADER)
		$(RM) $(BONUS_OBJS)
		@make -C $(LIBFTDIR)
		#$(CC) -o $(NAME) $(MLXFLAGS) -fsanitize=address $(STD_OBJS) $(OBJS) $(LIBFT)
		$(CC) $(STD_OBJS) $(OBJS) $(LIBFT) $(MLX) -fsanitize=address -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: $(BONUS_OBJS) $(OBJS) $(HEADER)
		$(RM) $(STD_OBJS)
		@make -C $(LIBFTDIR)
		#$(CC) -o $(NAME) $(MLXFLAGS) -fsanitize=address $(BONUS_OBJS) $(LIBFT)
		$(CC) $(OBJS) $(BONUS_OBJS) $(LIBFT) $(MLX) -fsanitize=address -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)


clean:
	$(RM) $(STD_OBJS) $(OBJS) $(BONUS_OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re
