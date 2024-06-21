/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:13 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 11:53:04 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief 
 * 
 * @param dest The destination buffer.
 * @param src The source string.
 * @param n The maximum number of characters to copy.
 * @return char* A pointer to the destination buffer.
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * @brief Get the iterator that points towards the end of the buffer
 * 
 * @param str 
 * @return int 
 */
int	get_end_line(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (str[i] && str[i] == SPACE)
		i--;
	return (i);
}

/**
 * @brief Check is the given `char` is either `N`, `S`, `E` or `W`
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}
