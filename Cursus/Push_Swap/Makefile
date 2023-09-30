# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 22:57:27 by akabbadj          #+#    #+#              #
#    Updated: 2023/09/29 20:13:29 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -g3

all : $(NAME)

PRINTF_PATH = ./libs/printf
LIBFT_PATH = ./libs/libft
ARGS_VALIDATION_PATH = ./src/args_validation
ERROR_HANDLING_PATH = ./src/error_handling
STACK_UTILES_PATH = ./src/stack_utiles
SORT_PATH = ./src/sort

PRINTF_LIB = $(PRINTF_PATH)/libftprintf.a
LIBFT_LIB = $(LIBFT_PATH)/libft.a
ARGS_VALIDATION_SRC = $(ARGS_VALIDATION_PATH)/args_validation.c $(ARGS_VALIDATION_PATH)/args_validation_utils.c
ERROR_HANDLING_SRC = $(ERROR_HANDLING_PATH)/error_handling.c
STACK_UTILES_SRC = $(STACK_UTILES_PATH)/stack_utiles.c $(STACK_UTILES_PATH)/stack_utiles_plus.c $(STACK_UTILES_PATH)/stack_initializer.c
SORT_MOVES_SRC = $(SORT_PATH)/moves/push.c $(SORT_PATH)/moves/rotate.c $(SORT_PATH)/moves/reverse_rotate.c $(SORT_PATH)/moves/swap.c
SORT_SRC= $(SORT_PATH)/sort.c $(SORT_PATH)/sort_utiles.c $(SORT_PATH)/small_sort.c $(SORT_PATH)/medium_sort.c $(SORT_PATH)/large_sort.c $(SORT_PATH)/large_sort_utiles.c

SRCS = main.c $(ARGS_VALIDATION_SRC) $(ERROR_HANDLING_SRC) $(STACK_UTILES_SRC) $(SORT_SRC) $(SORT_MOVES_SRC)

OBJS = $(SRCS:.c=.o)


.SILENT:
$(PRINTF_LIB) :
	$(MAKE) -C $(PRINTF_PATH)
	@echo "\n\033[36m printf lib built succusfuly 👋\033[0m\n"
	

$(LIBFT_LIB) :
	$(MAKE) -C $(LIBFT_PATH)
	@echo "\n\033[36m libft lib built succusfuly 👋\033[0m\n"

$(NAME) : $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	$(MAKE) clean
	@echo "\n\033[36m push_swap built succusfuly 👋\033[0m\n"

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	@echo "\n\033[36m object files removed 👋\033[0m\n"

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "\n\033[36m executables removed 👋\033[0m\n"

re : fclean all

.PHONY:	all clean fclean re
