# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:46:51 by akabbadj          #+#    #+#              #
#    Updated: 2023/02/15 17:53:57 by akabbadj         ###   ########.fr        #
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

SRCS = main.c utiles.c initializer.c julia.c mlx.c renderer.c mandelbrot.c complexe.c
OBJS = main.o utiles.o initializer.o julia.o mlx.o renderer.o mandelbrot.o complexe.o

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
	$(CC) $(OBJS) -L$(MLX_PATH) -lmlx $(LIBFT_PATH)/libft.a $(PRINT_F_PATH)/libftprintf.a $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f main.o utiles.o initializer.o julia.o mlx.o renderer.o mandelbrot.o complexe.o
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINT_F_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	@rm -f fractol
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINT_F_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) fclean

re : fclean all
	

