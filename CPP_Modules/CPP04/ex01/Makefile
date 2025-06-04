# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zblume <zblume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 10:49:24 by zblume            #+#    #+#              #
#    Updated: 2025/06/04 11:20:28 by zblume           ###   ########.fr        #
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

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

INCLUDES = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

OBJ_DIR = ./obj
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

NAME = Animals

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
