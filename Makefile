# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gateixei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:19:14 by gateixei          #+#    #+#              #
#    Updated: 2023/03/11 23:33:23 by gateixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Source ---

CLIENT_SRC = client.c
SERVER_SRC = server.c
LIBFT_SRC = libft/ft_strlen.c

# --- Constants ---
NAME = client server
CLIENT_NAME = client
SERVER_NAME = server
HEADER = minitalk.h
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address -o

# --- Objects ---

CLIENT_OBJ = $(CLIENT_SRC: .c=.o)
SERVER_OBJ = $(SERVER_SRC: .c=.o)
LIBFT_OBJ= $(LIBFT_SRC: .c=.o)

# --- Compile ---

all: $(SERVER_SRC) $(LIBFT_SRC) $(CLIENT_SRC) $(HEADER) $(NAME)

client: 
	@$(CC) $(CFLAGS) $(CLIENT_NAME) $(HEADER) $(CLIENT_SRC)
	@echo "\nClient is Ready, send me that PID!"

server: 
	@$(CC) $(CFLAGS) $(SERVER_NAME) $(HEADER) $(SERVER_SRC)
	@echo "\nServer is online!"

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all server client clean fclean re
