# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:46:51 by akabbadj          #+#    #+#              #
#    Updated: 2023/02/20 04:08:50 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

# CFLAGS = -Wall -Werror -Wextra 

MLX_FLAGS = -framework OpenGL -framework Appkit

LIBFT_PATH = ./libft
PRINT_F_PATH = ./printf
MLX_PATH = ./minilibx

LIBFT = $(LIBFT_PATH)/libft.a
PRINT = $(PRINT_F_PATH)/libftprintf.a
MLX = $(MLX_PATH)/libmlx.a

SRCS = main.c utiles.c initializer.c julia.c mlx.c renderer.c mandelbrot.c complexe.c hooks.c
OBJS = main.o utiles.o initializer.o julia.o mlx.o renderer.o mandelbrot.o complexe.o hooks.o

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
	@rm -f main.o utiles.o initializer.o julia.o mlx.o renderer.o mandelbrot.o complexe.o hooks.o
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINT_F_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	@rm -f fractol
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINT_F_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) fclean

re : fclean all
	

