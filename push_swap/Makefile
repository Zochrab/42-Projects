CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
SRC = 	$(addprefix $(SRC_DIR)/, \
		updater.c swap.c stack_ops.c sort_support.c simple_sort.c rotate.c \
		reverse_rotate.c push.c main.c error_checker.c free.c auxillary.c \
		radix_sort.c prize_calc.c turk_sort.c)

OBJ_DIR = ./obj
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBRARY = printflibft/libft.a
NAME= push_swap

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	@make bonus -C printflibft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -o $(NAME)

obj/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C printflibft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C printflibft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
