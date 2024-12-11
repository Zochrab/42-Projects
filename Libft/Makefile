# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zblume <zblume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 10:19:33 by zblume            #+#    #+#              #
#    Updated: 2023/11/22 11:17:47 by zblume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
      ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
      ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
      ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
      ft_striteri.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
        ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOBJ = $(BONUS:.c=.o)

NAME = libft.a
OPTIONS = -c

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[1;32m"
	@echo "##### Creating $(NAME) #####\033[35m "
	@echo "					███████╗██████╗ ██╗     ██╗   ██╗███╗   ███╗███████╗"
	@echo "					╚══███╔╝██╔══██╗██║     ██║   ██║████╗ ████║██╔════╝"
	@echo "					  ███╔╝ ██████╔╝██║     ██║   ██║██╔████╔██║█████╗  "
	@echo "					 ███╔╝  ██╔══██╗██║     ██║   ██║██║╚██╔╝██║██╔══╝  "
	@echo "					███████╗██████╔╝███████╗╚██████╔╝██║ ╚═╝ ██║███████╗"
	@echo "					╚══════╝╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝"
	@printf "\033[32m\033[7m"
	@echo "			-------------------------------------------------------------------------------------"
	@echo "			|                          Libft.a Successfully Created                             |"
	@echo "			-------------------------------------------------------------------------------------"
	@printf "\033[0m"
	ar rc $(NAME) $(OBJ)

%.o: %.c
	@printf "\033[1;36m##### Compiling: $<		[\033[0m"
	$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

bonus : $(BOBJ) $(NAME)
	@printf "\033[1;33m"
	@printf "\033[7m"
	@echo "			-------------------------------------------------------------------------------------"
	@echo "			|                                 Bonus added!                                      |"
	@echo "			-------------------------------------------------------------------------------------"
	@printf "\033[0m"
	ar r $(NAME) $(BOBJ)

clean:
	@printf "\033[1;31m"
	@printf "\033[7m"
	@echo "			-------------------------------------------------------------------------------------"
	@echo "			|                          .o Files Successfully Removed                            |"
	@echo "			-------------------------------------------------------------------------------------"
	@printf "\033[0m"
	rm -f $(OBJ)
	rm -f $(BOBJ)
	
fclean: clean
	@printf "\033[1;31m"
	@echo "##### Cleaning $(NAME) #####"
	@printf "\033[7m"
	@echo "			-------------------------------------------------------------------------------------"
	@echo "			|                          Libft.a Successfully Removed                             |"
	@echo "			-------------------------------------------------------------------------------------"
	@printf "\033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
