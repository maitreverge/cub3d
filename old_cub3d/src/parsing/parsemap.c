/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:27:42 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 14:55:42 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**parse_map_lines(t_map *map, int fd, char *line)
{
	char	**result;
	int		i;

	result = ft_rcalloc(NULL, 0, 1024);
	i = 0;
	while (1)
	{
		if (is_map_line(line))
		{
			result[i] = ft_strdup(line);
			if (map->map_width < ft_strlen(line))
				map->map_width = ft_strlen(line);
			i++;
			map->map_height++;
		}
		else if (!is_empty_line(line))
			parse_map_line_2(line, result, fd, map);
		free(line);
		line = get_line(fd);
		if (line == NULL || map->map_height >= 1024)
			break ;
	}
	return (result);
}

int	get_player_start_axis(t_map *map)
{
	long	i;
	int		j;

	i = -1;
	if (map->player_start_axis != -1)
		return (map->player_start_axis);
	while ((size_t)++i < map->map_height)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player_start_axis = char_to_axis(map->map[i][j]);
				map->player_start_x = j;
				map->player_start_y = i;
				return (map->player_start_axis);
			}
		}
	}
	printf(ERR_PRE"Player start not found"ERR_END);
	free_map_struct(map);
	exit(1);
}

/**
 * @brief Used for checking if there multiples arguments
 *  OR wrong paths on the wall texture lines
 * For Example :
 * NO : ./path_to_not_existing_texture ==> return false
 * NO : 123    456 ==> return false (multiple arguments)
 * 
 * 
 * @param split 
 * @return true 
 * @return false 
 */
bool	correct_texture_args(char **split)
{
	int	i;
	int	len_str;
	int	fd_texture;

	len_str = 0;
	i = 0;
	while (split[i])
	{
		len_str++;
		i++;
	}
	if (len_str != 2)
	{
		error_message("Incorrect texture path detected");
		return (false);
	}
	fd_texture = open(split[1], O_RDONLY);
	if (fd_texture == -1)
	{
		error_message("Can't access / open texture path");
		return (false);
	}
	return (true);
}

t_map	*parse_map(char *filename, t_map **main_map)
{
	char	*line;
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	map = *main_map;
	if (fd == -1)
		(perror("open"), exit(1));
	map = alloc_map_struct();
	init_mlx(&map);
	line = get_line(fd);
	while (line != NULL)
	{
		if (!parse_textures(line, map, fd) && !parse_textures_2(line, map, fd))
			if (parse_textures_3(line, map, fd))
				break ;
		free(line);
		line = get_line(fd);
	}
	close(fd);
	get_player_start_axis(map);
	check_map_complete(map);
	check_closed_map(map);
	return (map);
}
