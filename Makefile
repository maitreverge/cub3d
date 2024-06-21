# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 15:56:52 by flverge           #+#    #+#              #
#    Updated: 2024/06/21 22:05:49 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = cub3d

# Compiler && flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I includes/
# mettre -I pour eviter les chemins relatifs dans les headers

# C color print
# (absolute path to avoid conflict with echo builtin in dash without -e option)
ECHO = /bin/echo -e

# libft
LIBFT_NAME = libmaster.a
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# MiniLibX
MLX_FOLDER = MLX42/
MLX_NAME = libmlx42.a
MLX_PATH = MLX42/build/
MLX = $(MLX_PATH)$(MLX_NAME)

# cub3d files
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c) \
	$(wildcard $(SRC_DIR)/**/*.c)

OBJ := ${SRC:.c=.o}

# Includes
INC = -I./includes/ -I./MLX42/include/

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

all: $(MLX) $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_PATH)
	@$(ECHO) "\n"
	@$(ECHO) "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@$(ECHO) "\n"	

$(MLX):
	@$(ECHO) "$(BOLD)$(RED)🛠️      Compiling MiniLibX      🛠️$(RESET)"
	@$(ECHO) "\n"	
	@cd $(MLX_FOLDER) && cmake -B build && cmake --build build -j4 && cd ..
	@$(ECHO) "\n"	
	@$(ECHO) "$(BOLD)$(GREEN)😎     MiniLibX Compiled    😎$(RESET)"
	@$(ECHO) "\n"
	@$(ECHO) "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@$(ECHO) "\n"	

$(NAME): $(OBJ)
	@$(ECHO) "$(BOLD)$(RED)🛠️      Compiling cub3d    🛠️$(RESET)"
	@$(ECHO) "\n"
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(MLX) $(LIBFT) -ldl -lglfw -lm -lz -pthread -o $(NAME)
	@$(ECHO) "$(BOLD)$(GREEN)🚀      cub3d fully compiled, ready to use       🚀$(RESET)"
	@$(ECHO) "\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)
	@$(ECHO) "$(BOLD)$(ORANGE)🌀     Cleaned .o cub3d's files   🌀$(RESET)"
	@rm -rf $(MLX_PATH)
	@$(ECHO) "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files  🌀$(RESET)"


fclean: clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@$(ECHO) "$(BOLD)$(ORANGE)🌀     Cleaned cub3d exec       🌀$(RESET)"

bonus: all

re: fclean all
