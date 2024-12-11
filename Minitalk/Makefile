CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

LIBFT = libft/libft.a

CLIENT = client
SERVER = server
NAME = $(CLIENT) $(SERVER)

all: $(NAME)

$(NAME): $(LIBFT) $(CLIENT_OBJ) $(SERVER_OBJ)

client: $(LIBFT) $(CLIENT_SRC)
	@printf "\033[1;32m##### Creating Client	\033[0m\n"
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o client

server: $(LIBFT) $(SERVER_SRC)
	@printf "\033[1;32m##### Creating Server	\033[0m\n" 
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o server

%.o: %.c
	@printf "\033[1;36m##### Compiling $<	\033[0m\n"
	@$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

$(LIBFT):
	@make -s -C libft

clean:
	@printf "\033[1;31m##### Removing objects	\033[0m\n"
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@make -s -C libft clean

fclean: clean
	@printf "\033[1;31m##### Removing binaries	\033[0m\n"
	@rm -f $(CLIENT) $(SERVER)
	@make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re
