/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:17:39 by flverge           #+#    #+#             */
/*   Updated: 2024/06/22 13:19:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief 
 * 
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return int Returns an integer greater than, equal to,
 * or less than 0, depending on whether s1 is greater than, equal to,
 * or less than s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * @brief 
 * 
 * @param c The character to check.
 * @return int Returns 1 if the character is a whitespace character, 0 otherwise.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

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