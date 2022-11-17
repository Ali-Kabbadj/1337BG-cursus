# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 21:23:50 by akabbadj          #+#    #+#              #
#    Updated: 2022/11/17 21:23:54 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CC = cc

FLAGS = -c -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putunsigned.c ft_puthex.c ft_putptr.c ft_putpercent.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_memmove.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY:		all clean fclean re

  
