NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

PRINTF_DIR = ../01\ ft_printf
GNL_DIR = ../01\ get_next_line

SRC =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

PRINTF_SRC =	$(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/ft_print_char.c \
				$(PRINTF_DIR)/ft_print_hex.c \
				$(PRINTF_DIR)/ft_print_integer.c \
				$(PRINTF_DIR)/ft_print_pointer.c \
				$(PRINTF_DIR)/ft_print_string.c \
				$(PRINTF_DIR)/ft_print_udecimal.c

GNL_SRC =	$(GNL_DIR)/get_next_line_bonus.c \
			$(GNL_DIR)/get_next_line_utils_bonus.c


OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	clear

%.o: %.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	clear

extra: $(OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	ar rcs $(NAME) $(OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	clear

clean:
	rm -f $(OBJ) $(BONUS_OBJS) $(PRINTF_OBJ) $(GNL_OBJ)
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: all clean fclean re bonus