/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:04:58 by p          #+#    #+#             */
/*   Updated: 2024/04/23 09:31:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Check if the given WIN_HEIGHT and WIN_WIDTH parametters
 * are not negative or null.
 * 
 * @return true 
 * @return false 
 */
bool	incorrect_window_size(void)
{
	if (WIN_HEIGHT <= 0 || WIN_WIDTH <= 0)
	{
		error_message("Incorrect Window Size");
		return (true);
	}
	return (false);
}

/**
 * @brief Wrapper function safe malloc.
 * 
 * @param size 
 * @return void* 
 */
void	*secure_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		custom_exit(NULL, "Malloc failed allocating memory");
	return (result);
}

/**
 * @brief Wrapper function for clean exiting + message.
 * 
 * @param str 
 */
void	custom_exit(t_map *map_ptr, char *str)
{
	if (map_ptr)
		free_map_struct(map_ptr);
	printf(RED"⛔ %s ⛔\n"RESET, str);
	exit(1);
}

/**
 * @brief Print red error message to stdout
 * 
 * @param optionnal_message 
 */
void	error_message(char *optionnal_message)
{
	printf("Error : \n");
	printf(RED BOLD"⛔ %s ⛔\n\n"RESET, optionnal_message);
}
