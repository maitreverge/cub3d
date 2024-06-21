/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:32:48 by p          #+#    #+#             */
/*   Updated: 2024/04/22 19:34:40 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	texture_free(void *mlx, t_texture *texture)
{
	if (texture->img)
		mlx_destroy_image(mlx, texture->img);
	free(texture);
}

t_texture	*texture_load(t_map *map, char *path)
{
	t_texture	*texture;

	texture = secure_malloc(sizeof(t_texture));
	texture->img = mlx_xpm_file_to_image(map->mlx->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		printf("%s\n", path);
		free(texture);
		return (NULL);
	}
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return (texture);
}

void	texture_append(t_map *map, char *path, int index)
{
	t_texture	*texture;

	if (index < 0 || index > MAP_TEXTURES)
		custom_exit(map, "Invalid texture index");
	texture = texture_load(map, path);
	if (!texture)
		custom_exit(map, "Texture loading failed");
	map->textures[index] = texture;
}

void	texture_loadall(t_map *map)
{
	texture_append(map, map->north, 0);
	texture_append(map, map->south, 1);
	texture_append(map, map->east, 2);
	texture_append(map, map->west, 3);
}
