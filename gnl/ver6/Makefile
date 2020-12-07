SRC = main.c get_next_line.c get_next_line_utils.c

HEADER = get_next_line.h

all:
	gcc -Wall -Wextra -Werror $(SRC)

clang:
	clang -g -fsanitize=address $(SRC)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADER)
