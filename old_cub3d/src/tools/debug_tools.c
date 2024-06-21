/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:39:26 by p          #+#    #+#             */
/*   Updated: 2024/04/23 13:58:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map(t_map *map)
{
	int	i;

	printf("NO: %s\n", map->north);
	printf("SO: %s\n", map->south);
	printf("EA: %s\n", map->east);
	printf("WE: %s\n", map->west);
	printf("Floor color: %x\n", map->floor_color);
	printf("Ceiling color: %x\n", map->ceiling_color);
	printf("Player start axis: %d\n", map->player_start_axis);
	printf("Player start x: %d\n", map->player_start_x);
	printf("Player start y: %d\n", map->player_start_y);
	printf("Map:\n");
	i = -1;
	while (map->map[++i])
		printf("  %s\n", map->map[i]);
}
