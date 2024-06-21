# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:40:21 by flverge           #+#    #+#              #
#    Updated: 2023/11/16 10:41:35 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.


SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all