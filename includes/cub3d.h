/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:36:59 by flverge           #+#    #+#             */
/*   Updated: 2024/06/22 13:18:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Linking MLX header files
#include "../MLX42/include/MLX42/MLX42.h"

// Define libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <fcntl.h>


// Window Size
# define WIN_WIDTH 1000
# define WIN_HEIGHT 600

# define RED	 "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE	"\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[1m"
# define RESET   "\033[0m"

// ------------------------ FUNCTIONS DEFINITION -------------------------

// ============ EVENTS ===============

// events.c



// ============ PARSING ===============

// parsing.c


// ============ RENDER ===============

// render.c


// ============ UTILS ===============

// libft_extras.c
int	ft_strcmp(const char *s1, const char *s2);
int	ft_isspace(int c);
char	*ft_strncpy(char *dest, const char *src, size_t n);


// parsing_utils.c
void	print_usage(void);


// secure_functions.c
bool	incorrect_window_size(void);
void	*secure_malloc(size_t size);
void	custom_exit(const char *str);
void	error_message(const char *optionnal_message);



#endif