
LIBFT = ./libft/libft.a

NAME = libftprintf.a

CC = cc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

SRCS = ft_printf.c ft_putunsigned.c ft_puthex.c ft_putptr.c ft_putpercent.c ft_putnbr.c ft_putstr.c ft_putchar.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	make clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)
.PHONY:		all clean fclean re norm
re : fclean all

.PHONY:		all clean fclean re

  