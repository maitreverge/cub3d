/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:10:47 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 11:54:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <cub3d.h>

/**
 * @brief Print usage to stdout in case of incorrect arguments ac/av.
 * 
 */
void	print_usage(void)
{
	printf("Usage :\n");
	printf(GREEN BOLD"./cub3d   "RESET);
	printf(YELLOW BOLD"<path_to_valid_map>\n"RESET);
}

// I use double to avoid overflow
double	get_us(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

double	get_start_angle(char c)
{
	if (c == MAP_NORTH)
		return (M_PI);
	if (c == MAP_SOUTH)
		return (0);
	if (c == MAP_WEST)
		return (3 * M_PI / 2);
	return (M_PI / 2);
}

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
