# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gateixei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:19:14 by gateixei          #+#    #+#              #
#    Updated: 2023/03/12 22:54:38 by gateixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Source ---

CLIENT_SRC = ft_client/client.c
SERVER_SRC = ft_server/server.c
LIBFT = cd libft && make
LIB = libft/libft.a

# --- Constants ---

NAME = server client
CLIENT_NAME = client
SERVER_NAME = server
HEADER = include/minitalk.h
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address

# --- Objects ---

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
OBJS = $(CLIENT_NAME) $(SERVER_OBJ)

# --- Compile ---

all: start_lib server client

start_lib:
	@$(LIBFT)

server: $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(HEADER) $(LIB) -o $(SERVER_NAME)
	@echo "\nServer is online!"

client: $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(HEADER) $(LIB) -o $(CLIENT_NAME)
	@echo "\nClient is Ready, send me that PID!"

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all minitalk server client clean fclean re
