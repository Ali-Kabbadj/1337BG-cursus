# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 17:41:35 by akabbadj          #+#    #+#              #
#    Updated: 2023/03/08 17:53:49 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

PRINTF_PATH = ./printf
LIBFT_PATH = ./libft

PRINTF = $(PRINTF_PATH)/libftprintf.a
LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

SRCS = swap.c stack_helpers.c small_medium_sort.c rotate.c \
	reverse_rotate.c push.c main.c large_sort.c initializer.c  \
	helpers.c error_handler.c args_validator.c args_validator_utiles.c

OBJS = $(SRCS:.c=.o)

$(PRINTF) :
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_PATH)

$(NAME) : $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)
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