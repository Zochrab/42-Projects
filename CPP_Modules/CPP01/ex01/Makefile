# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zblume <zblume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 07:47:40 by zblume            #+#    #+#              #
#    Updated: 2025/04/09 10:39:14 by zblume           ###   ########.fr        #
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

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
OPTIONS = -c

SRC = main.cpp zombieHorde.cpp Zombie.cpp

INCLUDES = Zombie.hpp

OBJ_DIR = ./obj
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

NAME = HordeMaker

all:  $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@echo "$(GREEN)Compiling $(NAME)... $(RESET)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -g $(FLAGS) $(OPTIONS) $< -o $@
	@echo "$(BLUE)Compiling... $(CYAN)$<$(RESET)"

clean:
	@printf "$(MAGENTA)"
	@echo "$(RED)Deleting Objects... $(RESET)"
	@rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(MAGENTA)"
	@echo "$(RED)Deleting $(NAME)... $(RESET)"
	@rm -f $(NAME)
	@printf "$(RESET)"

re: fclean all

.PHONY: all re clean fclean libs debug
