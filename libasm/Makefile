# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 15:00:33 by tcider            #+#    #+#              #
#    Updated: 2021/02/02 12:13:51 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRCS = ft_strlen.s \
	   ft_strcpy.s \
	   ft_strcmp.s \
	   ft_write.s \
	   ft_read.s \
	   ft_strdup.s
BSRCS = ft_atoi_base_bonus.s \
		ft_list_push_front_bonus.s \
		ft_list_size_bonus.s \
		ft_list_sort_bonus.s \
		ft_list_remove_if_bonus.s
OBJS = $(SRCS:.s=.o)
BOBJS = $(BSRCS:.s=.o)
CMPL = gcc -Wall -Wextra -Werror
TEST = main.c bonus_test.c
TEST_HEADER = test.h
LIB_HEADER = libasm_bonus.h

%.o: %.s
	nasm -f macho64 $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test.out

test: bonus $(TEST) $(TEST_HEADER) $(LIB_HEADER)
	$(CMPL) -I. -L. -lasm $(TEST) -o test.out
	./test.out

test_debug: bonus $(TEST) $(TEST_HEADER) $(LIB_HEADER)
	clang -fsanitize=address -I. -L. -lasm $(TEST) -o test.out
	./test.out

re: fclean all

.PHONY: all re clean fclean test bonus test_debug
