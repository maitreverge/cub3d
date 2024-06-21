/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:23:52 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 12:26:23 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Wrapper function for norming
 * 
 * @param line 
 * @param result 
 * @param fd 
 * @param map 
 */
void	parse_map_line_2(char *line, char **result, int fd, t_map *map)
{
	printf(ERR_PRE"Invalid map line: %s"ERR_END, line);
	map->map = result;
	free_map_struct(map);
	free(line);
	close(fd);
	exit(1);
}

int	does_start_with(const char *line, const char *prefix)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || (line[i] >= '\t' && line[i] <= '\r'))
		i++;
	while (*prefix)
	{
		if (line[i++] != *prefix)
			return (0);
		prefix++;
	}
	return (line[i] != 0);
}

void	check_map_complete(t_map *map)
{
	if (map->north && map->south && map->east && map->west
		&& map->floor_color < INVALID_COLOR
		&& map->ceiling_color < INVALID_COLOR
		&& map->player_start_axis != -1
		&& map->player_start_x != -1
		&& map->player_start_y != -1 && map->map
		&& map->map_width && map->map_height)
		return ;
	if (!(map->floor_color == INVALID_COLOR
			|| map->ceiling_color == INVALID_COLOR))
		printf(ERR_PRE"Map is incomplete"ERR_END);
	free_map_struct(map);
	exit(1);
}

int	parse_color_component(char **str)
{
	int	tmp;

	while (**str == ' ')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
	{
		printf(ERR_PRE"Invalid color format: %s"ERR_END, *str);
		return (INVALID_COLOR);
	}
	tmp = ft_atoi(*str);
	if (tmp < 0 || tmp > 255)
	{
		printf(ERR_PRE"Invalid color format: %s"ERR_END, *str);
		return (INVALID_COLOR);
	}
	while (**str >= '0' && **str <= '9')
		(*str)++;
	return (tmp);
}

uint32_t	parse_color(char *str)
{
	unsigned int	tmp;
	uint32_t		result;
	int				i;

	result = 0;
	i = 0;
	while (i < 3)
	{
		tmp = parse_color_component(&str);
		if (tmp == INVALID_COLOR)
			return (INVALID_COLOR);
		result = (result << 8) | tmp;
		if (i < 2)
		{
			if (*str != ',')
			{
				printf(ERR_PRE"Invalid color format: %s"ERR_END, str);
				return (INVALID_COLOR);
			}
			str++;
		}
		i++;
	}
	return (result);
}
