CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putfunct.c ft_printf.c ft_hexconvert.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
OPTIONS = -c

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[1;32m"
	@echo "##### Creating $(NAME) #####\033[35m "
	@echo "		███████╗██████╗ ██╗     ██╗   ██╗███╗   ███╗███████╗"
	@echo "		╚══███╔╝██╔══██╗██║     ██║   ██║████╗ ████║██╔════╝"
	@echo "		  ███╔╝ ██████╔╝██║     ██║   ██║██╔████╔██║█████╗  "
	@echo "		 ███╔╝  ██╔══██╗██║     ██║   ██║██║╚██╔╝██║██╔══╝  "
	@echo "		███████╗██████╔╝███████╗╚██████╔╝██║ ╚═╝ ██║███████╗"
	@echo "		╚══════╝╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝"
	@printf "\033[32m\033[7m"
	@echo "	---------------------------------------------------------------------"
	@echo "	|                  libftprintf.a Successfully Created               |"
	@echo "	---------------------------------------------------------------------"
	@printf "\033[0m"
	ar rc $(NAME) $(OBJ)

%.o: %.c
	@printf "\033[1;36m##### Compiling: $<		[\033[0m"
	$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

clean:
	@printf "\033[1;31m"
	@printf "\033[7m"
	@echo "	---------------------------------------------------------------------"
	@echo "	|                  .o Files Successfully Removed                    |"
	@echo "	---------------------------------------------------------------------"
	@printf "\033[0m"
	rm -f $(OBJ)
	
fclean: clean
	@printf "\033[1;31m"
	@echo "##### Cleaning $(NAME) #####"
	@printf "\033[7m"
	@echo "	---------------------------------------------------------------------"
	@echo "	|                  libftprintf.a Successfully Removed               |"
	@echo "	---------------------------------------------------------------------"
	@printf "\033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
