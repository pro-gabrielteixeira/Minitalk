# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gateixei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 19:30:49 by gateixei          #+#    #+#              #
#    Updated: 2023/03/15 23:20:39 by gateixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = include/libft.h
SRC = ft_strlen.c ft_atoi.c ft_itoa.c ft_strdup.c ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf *.o
	@rm -rf include/libft.h.gch

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
