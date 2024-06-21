/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:56:49 by p          #+#    #+#             */
/*   Updated: 2024/04/22 18:58:32 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	*alloc_map_struct(void)
{
	t_map	*map;

	map = secure_malloc(sizeof(t_map));
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->font = NULL;
	map->floor_color = UNSET_COLOR;
	map->ceiling_color = UNSET_COLOR;
	map->player_start_axis = -1;
	map->player_start_x = -1;
	map->player_start_y = -1;
	map->map = NULL;
	map->map_width = 0;
	map->map_height = 0;
	map->mlx = secure_malloc(sizeof(t_mlx));
	ft_memset(map->textures, 0, sizeof(t_texture *) * MAP_TEXTURES);
	return (map);
}

/**
 * @brief This function safely init 3 pointers : `mlx`, `image`
 * and `windows`, essential for basic mlx functionning.
 * 
 * @param foo 
 */
void	init_mlx(t_map **foo)
{
	int		stupid_lib_without_null_checks;
	t_map	*map;
	t_mlx	*mlx;

	map = *foo;
	mlx = map->mlx;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		custom_exit(map, "Mlx init function failed");
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->window)
		failed_window(map);
	mlx->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->image)
		failed_image(map);
	mlx->image_data = (uint32_t *) mlx_get_data_addr(mlx->image,
			&stupid_lib_without_null_checks,
			&stupid_lib_without_null_checks,
			&stupid_lib_without_null_checks);
}
