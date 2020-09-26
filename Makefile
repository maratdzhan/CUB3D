# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iunity <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 19:44:51 by iunity            #+#    #+#              #
#    Updated: 2020/09/21 21:22:46 by iunity           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -O3 -Wall -Wextra -Werror

MLX = mlx

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h

SRC = cub3d \
	  gnl \
	  log \
	  parsing \
	  tools \
#	  parse \
	  parse_map \
	  parse_tools \
	  parse_check \
	  key \
	  screen \
	  screen_col \
	  sprite \
	  bitmap \

all: $(NAME)

FIL = $(addsuffix .c, $(addprefix srcs/, $(SRC)))

OBJ = $(FIL:.c=.o)

BIN = $(addsuffix .o, $(SRC))

$(NAME): $(OBJ)
	@echo "Compiling"
	$(CC) -o $(NAME) -L $(MLX) $(MLXFLAGS) $(OBJ)
	@echo "Compiling ready!"

clean:
	@echo "Call Cleaning"
	rm -rf $(OBJ) $(B_OBJ)
	rm -f bitmap.bmp
	@echo "cleaning ready"

fclean: clean
	@echo "Call full cleaning";
	rm -f $(NAME)
	@echo "full cleaning ready"

re: @echo "Rebuilding"
	fclean all

.PHONY: all clean fclean re 

