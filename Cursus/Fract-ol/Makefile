# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:46:51 by akabbadj          #+#    #+#              #
#    Updated: 2023/02/27 19:24:09 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

all: $(NAME)

CC = cc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -framework OpenGL -framework Appkit

LIBFT_PATH = ./libft
PRINT_F_PATH = ./printf
MLX_PATH = ./minilibx

LIBFT = $(LIBFT_PATH)/libft.a
PRINT = $(PRINT_F_PATH)/libftprintf.a
MLX = $(MLX_PATH)/libmlx.a

SRCS = main.c utiles.c \
	initializer.c julia.c renderer.c \
	mandelbrot.c hooks.c utiles2.c utiles3.c \
	input_handler.c formulas.c zoom.c hooks_helpers.c \
	burning_ship.c burning_ship_julia.c custom_julia.c
	
OBJS = $(SRCS:.c=.o)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINT):
	$(MAKE) -C $(PRINT_F_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS) $(MLX) $(PRINT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(PRINT) $(MLX_FLAGS) -o $(NAME)
	$(MAKE) clean

	
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean 
	$(MAKE) -C $(PRINT_F_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINT_F_PATH) fclean
	$(MAKE) -C $(MLX_PATH) fclean


re : fclean all
	

