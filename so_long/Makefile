CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP

SRC_DIR = ./src
SRC = $(addprefix $(SRC_DIR)/, \
		utlity.c so_long.c parse_map.c memory_management.c map_validate.c end_game.c\
		key_hook.c free.c error_handler.c dev_prints.c player_move.c graphics.c)
OBJ_DIR = ./obj
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

LIB_DIR = ./libs
LIBFT_DIR = $(LIB_DIR)/printflibft
GNL_DIR = $(LIB_DIR)/get_next_line
MLX_DIR = $(LIB_DIR)/minilibx-linux

LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL_LIB = $(GNL_DIR)/get_next_line.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

LIBS = $(LIBFT_LIB) $(MLX_LIB) $(GNL_LIB)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(GNL_LIB):
	@make -C $(GNL_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(GNL_DIR) clean
	@rm -f $(OBJ) $(DEP)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	rm -f $(MLX_LIB)
	@rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
