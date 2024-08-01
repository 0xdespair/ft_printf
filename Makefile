CC = cc
CFLAGS = -c -o -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_putstr.c ft_putchar.c \
	ft_printf.c ft_putnbr.c \
	ft_puthex.c ft_putptr.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
