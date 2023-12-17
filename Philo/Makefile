# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 02:10:30 by akabbadj          #+#    #+#              #
#    Updated: 2023/12/16 23:49:32 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
PTHREAD_FLAG = -pthread

OBJs_DIR = ./obj

SRCs = main.c validation.c init_data.c init_threads.c routine.c time.c
OBJs = $(patsubst %.c, $(OBJs_DIR)/%.o, $(SRCs))

all: $(NAME)

$(NAME): $(OBJs) 
	$(CC) $(CFLAGS) $(OBJs) -o $(NAME)


$(OBJs_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(PTHREAD_FLAG) -c -o $@ $< 

clean:
	rm -f $(OBJs)

fclean: clean
	rm -f philo
	
re: fclean
	$(MAKE) -C .
	 