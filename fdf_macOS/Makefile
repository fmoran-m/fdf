# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 22:22:31 by fmoran-m          #+#    #+#              #
#    Updated: 2024/02/10 13:39:19 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

CC = cc

LM = make -C

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a

INCLUDES = fdf.h

RM = rm -f

STD = std/inputs.c std/main.c std/transformation.c std/draw_map.c

STD_OBJS = ${STD:.c=.o}

SRC = src/put_img_pixel.c src/bressen.c src/rows_counter.c src/read_node.c src/get_map_line.c src/free_functions.c src/free_functions_2.c src/free_matrix.c src/file_checker.c src/init_functions.c src/read_map.c src/fdf_utils.c src/get_color.c src/get_color_utils.c

OBJS = ${SRC:.c=.o}

BONUS = bonus/main_bonus.c bonus/transformation_bonus.c bonus/inputs_bonus.c bonus/control_init_bonus.c bonus/rotation_bonus.c bonus/mouse_functions_bonus.c bonus/key_input_bonus.c bonus/control_reset_bonus.c bonus/constant_rotation_utils_bonus.c bonus/render_frame_bonus.c bonus/draw_map_bonus.c

BONUS_OBJS = ${BONUS:.c=.o}

$(NAME): $(STD_OBJS) $(OBJS) $(HEADER)
		$(RM) $(BONUS_OBJS)
		@$(LM) $(LIBFTDIR)
		$(CC) $(STD_OBJS) $(OBJS) $(LIBFT) $(MLX) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS) $(OBJS) $(HEADER)
		$(RM) $(STD_OBJS)
		@$(LM) $(LIBFTDIR)
		$(CC) $(OBJS) $(BONUS_OBJS) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(MLX) -o $(NAME) 

clean:
	$(RM) $(STD_OBJS) $(OBJS) $(BONUS_OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY = all clean fclean re bonus
