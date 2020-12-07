SRC = main.c get_next_line.c get_next_line_utils.c

SRC_BONUS = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

HEADER = get_next_line.h get_next_line_bonus.h

all:
	gcc -Wall -Wextra -Werror $(SRC)

clang:
	clang -g -fsanitize=address $(SRC)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(SRC_BONUS) $(HEADER)

bonus:
	clang -g -fsanitize=address $(SRC_BONUS)
