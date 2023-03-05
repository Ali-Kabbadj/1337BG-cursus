# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 18:30:46 by akabbadj          #+#    #+#              #
#    Updated: 2023/03/04 22:33:43 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERV = server
NAME_CLT = client
CFLAGS = -Wall -Werror -Wextra

CC = cc

PRINTF_PATH = ./printf
LIBF_PATH = ./libft

PRINTF = $(PRINTF_PATH)/libftprintf.a
LIBFT = $(LIBF_PATH)/libft.a

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBF_PATH)


all : $(NAME_SERV) $(NAME_CLT)


SRCS_SERV = server.c 
OBJS_SERV = server.o 

SRCS_CLT = client.c
OBJS_CLT = client.o 

$(NAME_SERV) : $(PRINTF) $(LIBFT) $(OBJS_SERV)
	$(CC) $(CFLAGS)  $(OBJS_SERV) $(PRINTF) $(LIBFT) -o $(NAME_SERV)
	$(MAKE) clean

$(NAME_CLT) : $(PRINTF) $(LIBFT) $(OBJS_CLT)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS_CLT) $(PRINTF) $(LIBFT) -o $(NAME_CLT)
	$(MAKE) clean

clean :
	rm -f $(OBJS_CLT) $(OBJS_SERV)
	$(MAKE) -C $(LIBF_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

fclean : clean
	rm -f $(NAME_CLT) $(NAME_SERV)
	$(MAKE) -C $(LIBF_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re : fclean all

.PHONY:		all clean fclean re