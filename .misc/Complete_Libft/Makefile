# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zblume <zblume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 15:15:22 by zblume            #+#    #+#              #
#    Updated: 2024/12/12 15:29:04 by zblume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m
RESET   = \033[0m

# Compiler
CC = cc
FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -Wall -Wextra -Werror -g
OPTIONS = -c
AR = ar rcs

# Directories
INC_DIR = ./inc
SRC_DIR = ./src
PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line
OBJ_DIR = ./obj
OBJ_DIR_DEBUG = ./obj_debug

# Includes
INCLUDES = $(addprefix $(INC_DIR)/, \
		ft_printf.h				\
		get_next_line.h			\
		libft.h					)

# Source Files
SRC = $(addprefix $(SRC_DIR)/, \
		ft_atoi.c				\
		ft_bzero.c				\
		ft_calloc.c				\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_isprint.c			\
		ft_itoa.c				\
		ft_lstadd_back.c		\
		ft_lstadd_front.c		\
		ft_lstclear.c			\
		ft_lstdelone.c			\
		ft_lstiter.c			\
		ft_lstlast.c			\
		ft_lstmap.c				\
		ft_lstnew.c				\
		ft_lstsize.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_putchar_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_split.c				\
		ft_strchr.c				\
		ft_strdup.c				\
		ft_striteri.c			\
		ft_strjoin.c			\
		ft_strlcat.c			\
		ft_strlcpy.c			\
		ft_strlen.c				\
		ft_strmapi.c			\
		ft_strncmp.c			\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_strtrim.c			\
		ft_substr.c				\
		ft_tolower.c			\
		ft_toupper.c			)

PRINTF_SRC = $(addprefix $(PRINTF_DIR)/, \
		ft_printf.c				\
		ft_putfunct.c			\
		ft_hexconvert.c			)

GNL_SRC = $(addprefix $(GNL_DIR)/, \
		get_next_line.c			\
		get_next_line_utils.c	)

# Object Files
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC) $(PRINTF_SRC) $(GNL_SRC)))
OBJ_DEBUG = $(patsubst %.c, $(OBJ_DIR_DEBUG)/%.o, $(notdir $(SRC) $(PRINTF_SRC) $(GNL_SRC)))

# Output
NAME = libft.a
NAME_DEBUG = libft_debug.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(OPTIONS) $< -o $@
	@echo "$(BLUE)Compiling... $(CYAN)$<$(RESET)"

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(OPTIONS) $< -o $@
	@echo "$(BLUE)Compiling printf... $(CYAN)$<$(RESET)"

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(OPTIONS) $< -o $@
	@echo "$(BLUE)Compiling GNL... $(CYAN)$<$(RESET)"

# Debug Rule
debug: $(NAME_DEBUG)

$(NAME_DEBUG): $(OBJ_DEBUG)
	@echo "$(YELLOW)Compiling debug $(DEBUG_NAME)...$(RESET)"
	@$(AR) $(NAME_DEBUG) $(OBJ_DEBUG)

$(OBJ_DIR_DEBUG)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR_DEBUG)
	@$(CC) $(DEBUG_FLAGS) $(OPTIONS) $< -o $@
	@echo "$(MAGENTA)Debug compiling... $(CYAN)$<$(RESET)"

$(OBJ_DIR_DEBUG)/%.o: $(PRINTF_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR_DEBUG)
	@$(CC) $(DEBUG_FLAGS) $(OPTIONS) $< -o $@
	@echo "$(MAGENTA)Debug compiling printf... $(CYAN)$<$(RESET)"

$(OBJ_DIR_DEBUG)/%.o: $(GNL_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR_DEBUG)
	@$(CC) $(DEBUG_FLAGS) $(OPTIONS) $< -o $@
	@echo "$(MAGENTA)Debug compiling GNL... $(CYAN)$<$(RESET)"

# Clean Rules
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_DEBUG)

fclean: clean
	@echo "$(RED)Cleaning $(NAME) and $(NAME_DEBUG)...$(RESET)"
	@rm -f $(NAME) $(NAME_DEBUG)

re: fclean all

debug_re: fclean debug

.PHONY: all clean fclean re debug debug_re
