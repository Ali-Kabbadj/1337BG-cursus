# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 02:13:30 by akabbadj          #+#    #+#              #
#    Updated: 2023/02/13 01:57:00 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

MLX_FLAGS = -framework OpenGL -framework AppKit


MLX = ./minilibx/libmlx.a

MLX_PATH = ./minilibx



SRC_NAME = 	hooks.c \
			initializer.c\
			main.c \
			renderer.c \
			utiles.c \
			mandelbrot.c \
			julia.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(SRC_NAME)

OBJ = $(OBJ_NAME)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $@ $^

sale: $(OBJ) $(MLX)
	@$(CC) $(MLX_FLAGS) -o $@ $^


$(MLX):
	@make -C $(MLX_PATH)

%.o : %.c $(MLX_PATH)
	@$(CC) -o $@ -c $< -I $(MLX_PATH)

clean:
	@make clean -C $(MLX_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
