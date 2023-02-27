# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:46:51 by akabbadj          #+#    #+#              #
#    Updated: 2023/02/26 21:30:41 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -framework OpenGL -framework Appkit

LIBFT_PATH = ./libft
PRINT_F_PATH = ./printf
MLX_PATH = ./minilibx

LIBFT = $(LIBFT_PATH)/libft.a
PRINT = $(PRINT_F_PATH)/libftprintf.a
MLX = $(MLX_PATH)/libmlx.a

SRCS = main.c utiles.c initializer.c julia.c renderer.c mandelbrot.c hooks.c utiles2.c utiles3.c input_handler.c formulas.c zoom.c hooks_helpers.c burning_ship.c burning_ship_julia.c custom_julia.c
OBJS = main.o utiles.o initializer.o julia.o renderer.o mandelbrot.o hooks.o utiles2.o utiles3.o input_handler.o formulas.o zoom.o hooks_helpers.o burning_ship.o burning_ship_julia.o custom_julia.o

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINT):
	$(MAKE) -C $(PRINT_F_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(MLX) $(PRINT) $(LIBFT)
	@$(CC) $(OBJS) -lm -L$(MLX_PATH) -lmlx $(LIBFT_PATH)/libft.a $(PRINT_F_PATH)/libftprintf.a $(MLX_FLAGS) -o $(NAME)
	@$(MAKE) clean
	
clean:
	@rm -f main.o utiles.o initializer.o julia.o renderer.o mandelbrot.o hooks.o utiles2.o utiles3.o input_handler.o formulas.o zoom.o hooks_helpers.o burning_ship.o burning_ship_julia.o  custom_julia.o
	@$(MAKE) -C $(LIBFT_PATH) clean 
	@$(MAKE) -C $(PRINT_F_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	@rm -f fractol
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINT_F_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) fclean

re : fclean all
	

