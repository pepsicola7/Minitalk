SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SERVER_SRC = server.c
CLIENT_SRC = client.c
SRC =	utile.c\
		ft_printf/ft_printf.c \
		ft_printf/ft_fonction.c

OBJ = $(SRC:.c=.o)
OBJ_SERVER = $(SERVER_SRC:.c=.o)
OBJ_CLIENT = $(CLIENT_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRC) $(OBJ_SERVER) $(OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ) $(OBJ_SERVER)

$(CLIENT) : $(CLIENT_SRC) $(OBJ_CLIENT) $(OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all