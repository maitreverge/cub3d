/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:00:46 by p          #+#    #+#             */
/*   Updated: 2024/04/24 14:53:02 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_map_struct(t_map *map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	(free(map->north), free(map->south), free(map->east), free(map->west));
	if (map->map)
	{
		while (i < map->map_height)
			free(map->map[i++]);
		free(map->map);
	}
	i = -1;
	while (++i < MAP_TEXTURES)
		if (map->textures[i])
			texture_free(map->mlx->mlx, map->textures[i]);
	font_free(map->font);
	mlx_destroy_image(map->mlx->mlx, map->mlx->image);
	mlx_destroy_window(map->mlx->mlx, map->mlx->window);
	mlx_destroy_display(map->mlx->mlx);
	(free(map->mlx->mlx), free(map->mlx), free(map));
}

/**
 * @brief Free both every char* and the char** holding them
 * 
 * @param to_free 
 */
void	free_split(char **to_free)
{
	int		i;

	if (!to_free)
		return ;
	i = 0;
	while (to_free[i] != NULL)
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

/**
 * @brief This function free and exit if mlx_new_windows failed
 * 
 * @param map 
 */
void	failed_window(t_map *map)
{
	custom_exit(map, "mlx_new_window function failed");
}

/**
 * @brief This function free and exit if mlx_new_image fails
 * 
 * @param map 
 */
void	failed_image(t_map *map)
{
	custom_exit(map, "mlx_new_image function failed");
}

/**
 * @brief Wrapper function for exiting proprelly when clicking mlx cross button
 * 
 * @param foo 
 * @return void* 
 */
int	free_cross(t_map **foo)
{
	t_map	*map;

	map = *foo;
	free_map_struct(map);
	printf("Exiting cub3d, see you soon !");
	exit(0);
}
