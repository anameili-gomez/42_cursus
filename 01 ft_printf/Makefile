NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_print_char.c \
		ft_print_string.c \
		ft_print_pointer.c \
		ft_print_integer.c \
		ft_print_udecimal.c \
		ft_print_hex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	clear

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: all clean fclean re
