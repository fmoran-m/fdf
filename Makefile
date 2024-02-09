# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 22:22:31 by fmoran-m          #+#    #+#              #
#    Updated: 2024/02/08 21:23:24 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = cc

LM = make -C

#CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

MLXINCLUDE = -I/usr/include -Imlx_linux -O3

INCLUDES = fdf.h

MLX = ./mlx/libmlx.a

RM = rm -f

STD = inputs.c main.c transformation.c

STD_OBJS = ${STD:.c=.o}

SRC = put_img_pixel.c bressen.c rows_counter.c read_node.c get_map_line.c draw_map.c free_functions.c free_functions_2.c free_matrix.c file_checker.c init_functions.c read_map.c fdf_utils.c get_color.c get_color_utils.c

OBJS = ${SRC:.c=.o}

BONUS = main_bonus.c transformation_bonus.c inputs_bonus.c control_init_bonus.c rotation_bonus.c mouse_functions_bonus.c key_input_bonus.c control_reset_bonus.c constant_rotation_utils_bonus.c

BONUS_OBJS = ${BONUS:.c=.o}

$(NAME): $(STD_OBJS) $(OBJS) $(HEADER)
		$(RM) $(BONUS_OBJS)
		@$(LM) $(LIBFTDIR)
		#$(CC) -o $(NAME) $(CFLAGS) $(MLXFLAGS) $(STD_OBJS) $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(STD_OBJS) $(LIBFT) $(MLX) -fsanitize=address -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(MLXINCLUDE) -c $< -o $@

bonus: $(BONUS_OBJS) $(OBJS) $(HEADER)
		$(RM) $(STD_OBJS)
		@$(LM) $(LIBFTDIR)
		#$(CC) -o $(NAME) $(CFLAGS) $(MLXFLAGS) $(BONUS_OBJS) $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(BONUS_OBJS) $(LIBFT) $(MLX) -fsanitize=address -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

clean:
	$(RM) $(STD_OBJS) $(OBJS) $(BONUS_OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re bonus
