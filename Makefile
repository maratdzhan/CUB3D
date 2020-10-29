NAME = cub3D

CC = gcc

CFLAGS = -O3 -Wall -Wextra -Werror

MLX = mlxopengl

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h

SRC = cub3d \
	parse \
	parse_map \
	parse_tools \
	parse_check \
	ext_map_checking \
	gnl \
	key \
	screen \
	screen_col \
	sprite \
	bitmap \
	tools \
	errors \

FIL = $(addsuffix .c, $(addprefix files/, $(SRC)))

OBJ = $(FIL:.c=.o)

BIN = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re bonus test sqr bmp err inv norm

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[0;33mCompiling..."
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	rm -rf $(OBJ) $(B_OBJ)
	rm -f bitmap.bmp
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

bmp: re
	./$(NAME) maps/map.cub --save

norm:
	norminette $(FIL) $(B_FIL) files/$(HEADER) bonus/$(B_HEADER)
