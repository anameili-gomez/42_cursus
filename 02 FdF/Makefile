NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra $(HEADERS)
HEADERS = -I"../01 get_next_line" -I"../01 ft_printf" -I"../00 Libft"

LIBMLX = ./MLX42/
MLX_HEADERS = -I ./include -I $(LIBMLX)/include 
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)

LIBFT_DIR = ../00\ Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	Fdf.c \
		utils/map.c \
		utils/points.c \
		utils/drawing.c \
		utils/2D.c \
		utils/free_exit.c

SRC_BONUS =	Fdf_bonus.c \
			utils_bonus/map_bonus.c \
			utils_bonus/points_bonus.c \
			utils_bonus/colors_bonus.c \
			utils_bonus/isometric_bonus.c \
			utils_bonus/drawing_bonus.c \
			utils_bonus/hooks_loops_bonus.c \
			utils_bonus/2D_bonus.c \
			utils_bonus/free_exit_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o "$@" -c "$<" $(MLX_HEADERS)

all: MLX $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX_HEADERS) -o $(NAME) -lm
	clear

bonus: MLX $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) $(MLX_HEADERS) -o $(NAME) -lm
	clear

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) extra

MLX:
	if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/42-Fundacion-Telefonica/MLX42.git; \
	fi
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4;

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFT_DIR) clean
	clear

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBMLX)
	$(MAKE) -C $(LIBFT_DIR) fclean
	clear

re: fclean all

.PHONY: all clean fclean re MLX
