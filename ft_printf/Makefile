# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 17:44:02 by tcider            #+#    #+#              #
#    Updated: 2020/12/05 10:52:43 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = ./libft

SRC_DIR = ./src

HEADER_DIR = ./includes

HEADER = ft_printf.h

SRC = ft_printf.c aux_printf.c aux_printf_hex.c aux_printf_chars.c \
aux_printf_float.c aux_printf_eg.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: $(SRC_DIR)/%.c $(HEADER_DIR)/$(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I$(HEADER_DIR)

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

bonus: all

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
