# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:46:51 by akabbadj          #+#    #+#              #
#    Updated: 2023/03/01 00:17:16 by akabbadj         ###   ########.fr        #
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

SRCS = main.c input_handler.c \
	initializer.c renderer.c \
	utiles.c defaults.c utiles3.c \
	hooks.c hooks_helpers.c zoom.c \
	iteration.c  formulas.c
	
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
	

