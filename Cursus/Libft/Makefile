# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 09:09:12 by akabbadj          #+#    #+#              #
#    Updated: 2022/10/24 00:30:41 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_islower.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_atoi.c \
	   ft_isprint.c ft_memset.c ft_striteri.c ft_strrchr.c \
	   ft_bzero.c ft_isupper.c ft_putchar_fd.c ft_strjoin.c  \
	   ft_strtrim.c ft_calloc.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c \
	   ft_substr.c ft_isalnum.c ft_memccpy.c ft_putnbr_fd.c \
	   ft_strlcpy.c ft_tolower.c ft_isalpha.c ft_memchr.c \
	   ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isascii.c \
	   ft_memcmp.c ft_split.c ft_strmapi.c \
	   ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strncmp.c \

OBJS =  $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

RM: rm -f

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re

re: fclean all

