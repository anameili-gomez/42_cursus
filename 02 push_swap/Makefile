NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra $(HEADERS)
HEADERS = -I"../01 ft_printf" -I"../00 Libft"

LIBFT_DIR = ../00\ Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	push_swap.c \
		utils/errors.c \
		utils/get_stack.c \
		utils/indexes.c \
		utils/free_and_exit.c \
		utils/ft_atol.c \
		movements/swap.c \
		movements/push.c \
		movements/rotate.c \
		movements/reverse_rotate.c \
		sorting/sorting.c \
		sorting/simple_sort.c \
		sorting/main_sort.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	clear

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) extra

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	clear

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	clear

re: fclean all

.PHONY: all clean fclean re
