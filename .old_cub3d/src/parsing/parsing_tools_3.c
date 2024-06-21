/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:55:54 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 15:05:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_textures(char *line, t_map *map, int fd)
{
	if (does_start_with(line, "NO "))
	{
		check_if_already_set(map, map->north, fd, line);
		check_texture(line, &map->north);
		return (1);
	}
	else if (does_start_with(line, "SO "))
	{
		check_if_already_set(map, map->south, fd, line);
		check_texture(line, &map->south);
		return (1);
	}
	else if (does_start_with(line, "EA "))
	{
		check_if_already_set(map, map->east, fd, line);
		check_texture(line, &map->east);
		return (1);
	}
	else if (does_start_with(line, "WE "))
	{
		check_if_already_set(map, map->west, fd, line);
		check_texture(line, &map->west);
		return (1);
	}
	return (0);
}

int	parse_textures_2(char *line, t_map *map, int fd)
{
	if (does_start_with(line, "F "))
	{
		check_if_already_set(map,
			(char *)(size_t) map->floor_color - UNSET_COLOR, fd, line);
		map->floor_color = parse_color(line + 2);
		return (1);
	}
	else if (does_start_with(line, "C "))
	{
		check_if_already_set(map,
			(char *)(size_t) map->ceiling_color - UNSET_COLOR, fd, line);
		map->ceiling_color = parse_color(line + 2);
		return (1);
	}
	return (0);
}

int	parse_textures_3(char *line, t_map *map, int fd)
{
	if (is_map_line(line))
	{
		check_if_already_set(map, (char *)map->map, fd, line);
		map->map = parse_map_lines(map, fd, line);
		return (1);
	}
	else if (!is_empty_line(line))
	{
		printf(ERR_PRE"is_empty_line activated: %s"ERR_END, line);
		close(fd);
		free(line);
		free_map_struct(map);
		exit(1);
	}
	return (0);
}

bool	is_safe_step_ok(char **map, int i, int j)
{
	char	target;

	target = map[i][j];
	if (target == SPACE || target == '\n' || target == 0)
		return (false);
	return (true);
}

/**
 * @brief Detect if there is a '0' on the first and last line.
 * If it does, exit the program.
 * Maybe a little bit over_killed, but more safe.
 * 
 * @param real_map 
 * @param map 
 */
void	parse_first_last_line(char *real_map, t_map *map)
{
	int	j;

	j = 0;
	while (j < (int)map->map_width && real_map[j] != 0)
	{
		if (real_map[j] == '0')
			custom_exit(map, "0 detected on the first / last line of the map");
		j++;
	}
}
