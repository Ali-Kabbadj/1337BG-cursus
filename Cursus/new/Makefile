NAME = fract-ol
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c initializer.c hooks.c renderer.c julia.c
OBJS = main.o initializer.o hooks.o renderer.o julia.o

all = $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf main.o initializer.o hooks.o renderer.o julia.o

fclean: clean
	rm -rf fract-ol