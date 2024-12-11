# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zblume <zblume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 14:55:00 by zblume            #+#    #+#              #
#    Updated: 2024/11/30 17:47:38 by zblume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m
RESET   = \033[0m


CC = cc
FLAGS = -Wall -Werror -Wextra
#FSAN = -fsanitize=thread

SRC_DIR = ./src
SRC = $(addprefix $(SRC_DIR)/, \
	actions.c init.c main.c routine.c monitor.c utils.c)

OBJ_DIR = ./obj
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

INCLUDES = philosophers.h

NAME = philo

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "$(GREEN)Compiling $(NAME)... $(RESET)"
	@$(CC) $(FLAGS) $(FSAN) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $(NAME)

obj/%.o:$(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(FSAN) -c $< -o $@
	@echo "$(BLUE)Compiling... $(CYAN)$<$(RESET)"

clean:
	@echo "$(RED)Deleting Objects... $(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Deleting $(NAME)... $(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
