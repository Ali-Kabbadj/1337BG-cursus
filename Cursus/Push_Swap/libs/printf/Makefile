# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 21:23:50 by akabbadj          #+#    #+#              #
#    Updated: 2023/09/28 10:28:06 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putunsigned.c ft_puthex.c ft_putptr.c ft_putpercent.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_memmove.c
OBJS = $(SRCS:.c=.o)

.SILENT:
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	$(MAKE) clean

all : $(NAME)

RM: rm -f

clean :
	rm -rf $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY:		all clean fclean re