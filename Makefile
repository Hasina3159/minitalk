CLIENT = client

SERVER = server

CC = cc 

FLAGS = -Wall -Werror -Wextra

SRC_CLIENT = client_src/client.c client_src/utils.c

OBJ_CLIENT = client_src/client.o

SRC_SERVER = server_src/server.c server_src/utils.c

OBJ_SERVER = server_src/server.o

$(CLIENT) : $(SRC_CLIENT)
	$(CC) $(SRC_CLIENT) $(FLAGS)  -o  $(CLIENT)

$(SERVER) : $(SRC_SERVER)
	$(CC) $(FLAGS) $(SRC_SERVER) -o  $(SERVER) -g

all : $(CLIENT) $(SERVER)

clean : $(OBJ_CLIENT) $(OBJ_SERVER)
	rm $(OBJ_SERVER) $(OBJ_CLIENT)

fclean : clean
	rm $(CLIENT) $(SERVER)

re : fclean all