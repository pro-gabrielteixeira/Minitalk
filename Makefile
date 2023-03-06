# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gateixei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:19:14 by gateixei          #+#    #+#              #
#    Updated: 2023/03/06 22:02:57 by gateixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Source ---

CLIENT_SRC = client.c
SERVER_SRC = server.c

# --- Constants ---

CC = gcc
CFLAGS = -Wextra -Wall -Werror
SERVER_NAME = server
CLIENT_NAME = client

# --- Compile ---

all: server client

server: $(SERVER_SRC)
	@$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER_NAME)
	@echo "\nServer is online!"

client: $(CLIENT_SRC)
	@$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT_NAME)
	@echo "\nClient is Ready, send me that PID!"

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all server client clean fclean re
