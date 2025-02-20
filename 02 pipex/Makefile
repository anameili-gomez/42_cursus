NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra $(HEADERS)
HEADERS = -I"../01 get_next_line" -I"../00 Libft"

LIBFT_DIR = ../00\ Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	pipex.c \
		utils.c

BONUS_SRC =	bonus/pipex_bonus.c \
			bonus/children_bonus.c \
			bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	clear

bonus: $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)
	clear

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) extra

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	clear

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	clear

re: fclean all

.PHONY: all clean fclean re bonus
