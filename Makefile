# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Output files (executables)
NAME_SERVER = server
NAME_CLIENT = client

# Rules
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER)

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean

re: fclean all

.SECONDARY: $(OBJS_CLIENT) $(OBJS_SERVER)

.PHONY: all clean fclean re