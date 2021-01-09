# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 17:44:02 by tcider            #+#    #+#              #
#    Updated: 2021/01/04 18:13:26 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LIBFT = libft.a

LIBFT_DIR = ./libft/

MLXLIB = libmlx.dylib

MLXLIB_DIR = ./mlx_mms/

MLX_FLAGS = -framework OpenGL -framework AppKit

SRC_DIR = src/

OBJ_DIR = obj/

HEADER_DIR = ./includes/

HEADERS = ft_minirt.h get_next_line.h constants.h

SRC = main.c parse_main.c get_next_line.c get_next_line_utils.c error.c \
parse_scene.c save.c parse_figures.c rt_main.c rt_dist.c rt_color.c \
rt_color_utils.c rt_move.c rt_dist_cy.c

SRC_LIST = $(addprefix $(SRC_DIR),$(SRC))

OBJ_LIST = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_LIST)) 

HEADER_LIST = $(addprefix $(HEADER_DIR),$(HEADERS))

COMPILE = gcc -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_LIST)
	mkdir -p $(OBJ_DIR)
	$(COMPILE) -c $< -o $@ -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(MLXLIB_DIR)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(MLXLIB):
	$(MAKE) -C $(MLXLIB_DIR)
	cp $(MLXLIB_DIR)$(MLXLIB) ./

$(NAME): $(OBJ_LIST) $(LIBFT_DIR)$(LIBFT) $(MLXLIB)
	$(COMPILE) -o $(NAME) $(OBJ_LIST) -L$(LIBFT_DIR) -lft -L. -lmlx $(MLX_FLAGS)

bonus: all

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLXLIB_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

libclean: fclean
	rm -f $(MLXLIB)

re: fclean all

.PHONY: all clean fclean re bonus libclean
