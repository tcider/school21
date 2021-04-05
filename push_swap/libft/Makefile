# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 11:30:04 by tcider            #+#    #+#              #
#    Updated: 2021/04/01 14:46:23 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER_DIR = ../includes

SRC_ALL = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_strncmp.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putchar.c \
	  ft_putnchar.c \
	  ft_putnstr.c \
	  ft_litoa.c \
	  ft_ulitoa.c \
	  ft_straddc.c \
	  ft_strwchar.c \
	  ft_caddstr.c \
	  ft_islcase.c \
	  ft_strdelc.c \
	  ft_cdelstr.c \
	  ft_minignl.c \
	  ft_strcmp.c \
	  ft_strtoi.c \
	  ft_strtof.c \
	  ft_splitn.c \
	  ft_splitw.c \
	  ft_strtoi_int.c \
	  ft_strcmp_spaced.c \
	  ft_arr.c \
	  ft_arr_lcis.c \
	  ft_arr_lcis_ind.c \
	  ft_lstnew.c \
	  ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_veclib1.c \
	  ft_veclib2.c \
	  ft_stack1.c \
	  ft_stack2.c \
	  ft_stack3.c \
	  ft_stack4.c \
	  ft_stack5.c \
	  ft_stack6.c \
	  ft_math.c \
	  ft_heapstr.c

SRC_PUSH_SWAP = ft_strtoi_int.c \
				ft_strcmp.c \
				ft_strcmp_spaced.c \
				ft_strlcpy.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_strlen.c \
				ft_arr.c \
				ft_arr_lcis.c \
				ft_arr_lcis_ind.c \
				ft_stack1.c \
				ft_stack2.c \
				ft_stack3.c \
				ft_stack4.c \
				ft_stack5.c \
				ft_stack6.c \
				ft_math.c \
				ft_heapstr.c

OBJ_ALL = $(SRC_ALL:.c=.o)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

%.o: %.c $(HEADER_DIR)/$(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I$(HEADER_DIR)

$(NAME): $(OBJ_ALL)
	ar rc $(NAME) $(OBJ_ALL)
	ranlib $(NAME)

push_swap: $(OBJ_PUSH_SWAP)
	ar rc $(NAME) $(OBJ_PUSH_SWAP)
	ranlib $(NAME)

clean:
	rm -f $(OBJ_ALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
