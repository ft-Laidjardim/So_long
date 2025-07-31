NAME = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c
SRC_CLIENT = client.c

all: server client

server:
	$(CC) $(CFLAGS) $(SRC_SERVER) -o server

client:
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o client

clean:
	rm -f *.o

fclean: clean
	rm -f server client

re: fclean all
