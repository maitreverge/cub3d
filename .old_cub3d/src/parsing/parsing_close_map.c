/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_close_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:35:38 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 15:40:46 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Check if the line end with a '1'
 * 
 * @param real_map 
 * @param end 
 * @param j 
 * @param map 
 */
void	check_left_right(char *real_map, t_map *s_map)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(real_map) - 1;
	while (real_map[start] == SPACE)
		start++;
	if (real_map[start] && real_map[start] != '1')
		custom_exit(s_map, "Map left side does not start with a '1'");
	while (real_map[end] == SPACE)
		end--;
	if (real_map[end] && end != start && real_map[end] != '1')
		custom_exit(s_map, "Map right side does not start with a '1'");
}

void	circle_zero_check(char **map, int *old_i, int *old_j, t_map *s_map)
{
	int	i;
	int	j;

	i = *old_i;
	j = *old_j;
	if (!is_safe_step_ok(map, i + 1, j))
		custom_exit(s_map, "vertical_circle_check");
	if (!is_safe_step_ok(map, i - 1, j))
		custom_exit(s_map, "vertical_circle_check");
	if (!is_safe_step_ok(map, i, j - 1))
		custom_exit(s_map, "horizontal_circle_check");
	if (!is_safe_step_ok(map, i, j + 1))
		custom_exit(s_map, "horizontal_circle_check");
	if (!is_safe_step_ok(map, i - 1, j - 1))
		custom_exit(s_map, "1_diagonal_circle_check");
	if (!is_safe_step_ok(map, i + 1, j + 1))
		custom_exit(s_map, "2_diagonal_circle_check");
	if (!is_safe_step_ok(map, i + 1, j - 1))
		custom_exit(s_map, "3_diagonal_circle_check");
	if (!is_safe_step_ok(map, i - 1, j + 1))
		custom_exit(s_map, "4_diagonal_circle_check");
}

static void	parse_before_limits(char **real_map, t_map *s_map, int *old_i)
{
	int	i;
	int	end;
	int	start;

	start = 0;
	i = *old_i;
	end = get_end_line(real_map[i]);
	while (real_map[i][start] == SPACE)
		start++;
	check_left_right(real_map[i], s_map);
	while (start < end)
	{
		if (real_map[i][start] == '0')
			circle_zero_check(real_map, &i, &start, s_map);
		start++;
	}
}

void	check_closed_map_1(int i, int j, char **real_map, t_map *map)
{
	bool	player;

	player = false;
	while (i < (int)map->map_height && real_map[i] != NULL)
	{
		j = 0;
		while (j < (int)map->map_width && real_map[i][j] != 0)
		{
			if (is_player(real_map[i][j]))
			{
				if (!player)
					player = true;
				else
					custom_exit(map, "Double player detected");
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief yes
 * 
 * @param map 
 */
void	check_closed_map(t_map *map)
{
	char	**real_map;
	int		i;

	i = 0;
	real_map = map->map;
	check_closed_map_1(0, 0, real_map, map);
	while (i < (int)map->map_height && real_map[i] != NULL)
	{
		if ((i == 0 || i + 1 == (int)map->map_height))
			parse_first_last_line(real_map[i], map);
		else
			parse_before_limits(real_map, map, &i);
		i++;
	}
}
