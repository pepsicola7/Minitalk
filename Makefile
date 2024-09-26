SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c
CLIENT_SRC = client.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRC)

$(CLIENT) : $(CLIEN_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIEN_SRC)

clean:
	rm -f $(SERVER) $(CLIENT)

re: clean all