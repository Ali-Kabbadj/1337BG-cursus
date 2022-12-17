# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 10:47:02 by akabbadj          #+#    #+#              #
#    Updated: 2022/12/17 15:38:19 by akabbadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CFLAGS = -Wall -Werror -Wextra

SRCS = test.c render_shapes.c renderer.c complex.c 
OBJS = test.o render_shape.o renderer.o complex.o

%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf test.o render_shape.o renderer.o

fclean: clean
	rm -rf fract-ol
	