# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 22:57:27 by akabbadj          #+#    #+#              #
#    Updated: 2023/09/01 06:00:32 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra

PRINTF_PATH = ./printf
LIBFT_PATH = ./libft

PRINTF_LIB = $(PRINTF_PATH)/libftprintf.a
LIBFT_LIB = $(LIBFT_PATH)/libft.a

all : $(NAME)

SRCS = main.c args_validation.c error_handling.c args_validation_utils.c

OBJS = $(SRCS:.c=.o)

$(PRINTF_LIB) :
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT_LIB) :
	$(MAKE) -C $(LIBFT_PATH)

$(NAME) : $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	$(MAKE) clean

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all
