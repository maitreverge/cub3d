/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:57:06 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 14:37:35 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_empty_line(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == 0);
}

int	is_map_line(char *line)
{
	while (*line == SPACE)
		line++;
	if (!*line)
		return (0);
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N'
			&& *line != 'S' && *line != 'E' && *line != 'W' && *line != SPACE)
			return (0);
		line++;
	}
	return (1);
}

int	char_to_axis(char c)
{
	if (c == 'N')
		return (MAP_NORTH);
	if (c == 'S')
		return (MAP_SOUTH);
	if (c == 'E')
		return (MAP_EAST);
	if (c == 'W')
		return (MAP_WEST);
	return (-1);
}

/**
 * @brief Refactoring function for both checking
 * and assigning textures to structure
 * 
 * @param line 
 * @param orientation 
 */
void	check_texture(char *line, char **orientation)
{
	char	**split;

	split = ft_split(line, SPACE);
	if (correct_texture_args(split))
		*orientation = ft_strdup(split[1]);
	free_split(split);
}

void	check_if_already_set(t_map *map, char *str, int fd, char *line)
{
	if (!str)
		return ;
	printf(ERR_PRE"Duplicate map parameter: %s"ERR_END, line);
	close(fd);
	free(line);
	free_map_struct(map);
	exit(1);
}
