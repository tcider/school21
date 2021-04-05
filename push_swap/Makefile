# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 16:01:38 by tcider            #+#    #+#              #
#    Updated: 2021/04/02 12:04:49 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

LIBFT = libft.a

LIBFT_DIR = ./libft/

SRC_DIR = srcs/

OBJ_DIR = obj/

HEADER_DIR = ./includes/

HEADERS = get_next_line.h push_swap.h

SRC1 = checker.c get_next_line.c get_next_line_utils.c shared_part1.c \
	operations_part1.c operations_part2.c operations_part3.c shared_part2.c

SRC2 = push_swap.c shared_part1.c shared_part2.c operations_part1.c \
	operations_part2.c operations_part3.c sort_utils_part1.c \
	sort_utils_part2.c sort_utils_part3.c

SRC_LIST1 = $(addprefix $(SRC_DIR),$(SRC1))

SRC_LIST2 = $(addprefix $(SRC_DIR),$(SRC2))

OBJ_LIST1 = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_LIST1)) 

OBJ_LIST2 = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_LIST2)) 

HEADER_LIST = $(addprefix $(HEADER_DIR),$(HEADERS))

COMPILE = gcc -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_LIST)
	mkdir -p $(OBJ_DIR)
	$(COMPILE) -c $< -o $@ -I$(HEADER_DIR) -I$(LIBFT_DIR)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) push_swap -C $(LIBFT_DIR)

$(NAME1): $(OBJ_LIST1) $(LIBFT_DIR)$(LIBFT)
	$(COMPILE) -o $(NAME1) $(OBJ_LIST1) -L$(LIBFT_DIR) -lft

$(NAME2): $(OBJ_LIST2) $(LIBFT_DIR)$(LIBFT)
	$(COMPILE) -o $(NAME2) $(OBJ_LIST2) -L$(LIBFT_DIR) -lft

bonus: all

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re bonus
