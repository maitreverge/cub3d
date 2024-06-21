/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:05 by p          #+#    #+#             */
/*   Updated: 2024/04/24 14:05:21 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

typedef struct s_bresenham
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;
	double	e2;
	double	x;
	double	y;
}	t_bresenham;

void	bresenham(t_map *map, t_bresenham *bre, double a, double b)
{
	while (1)
	{
		if (map->mlx->image_data[(int) bre->y * WIN_WIDTH + (int) bre->x]
			== 0x000000)
			break ;
		map->mlx->image_data[(int) bre->y * WIN_WIDTH + (int) bre->x]
			= 0xdd5555;
		if (a == bre->x && b == bre->y)
			break ;
		bre->e2 = 2 * bre->err;
		if (bre->e2 > -bre->dy)
		{
			bre->err -= bre->dy;
			bre->x += bre->sx;
		}
		if (bre->e2 < bre->dx)
		{
			bre->err += bre->dx;
			bre->y += bre->sy;
		}
	}
}

void	minimap_add_angle(t_map *map)
{
	t_bresenham	bre;
	double		a;
	double		b;
	double		i;

	i = -FOV / 2;
	while (i < FOV / 2)
	{
		bre.x = map->player_ptr->x * MINIMAP_SCALE + MMAP_OFFSET;
		bre.y = map->player_ptr->y * MINIMAP_SCALE + MMAP_OFFSET;
		a = (map->player_ptr->x + sin(map->player_ptr->angle + i) * 5)
			* MINIMAP_SCALE + MMAP_OFFSET;
		b = (map->player_ptr->y + cos(map->player_ptr->angle + i) * 5)
			* MINIMAP_SCALE + MMAP_OFFSET;
		bre.dx = fabs(a - bre.x);
		bre.dy = fabs(b - bre.y);
		bre.sx = t(a > bre.x, 1, -1);
		bre.sy = t(b > bre.y, 1, -1);
		bre.err = bre.dx - bre.dy;
		bresenham(map, &bre, a, b);
		i += 0.01;
	}
}

void	draw_shadow_box(t_map *map, t_point start, t_point end)
{
	unsigned int	i;
	unsigned int	j;

	i = start.y;
	while (i < end.y)
	{
		j = start.x;
		while (j < end.x)
		{
			map->mlx->image_data[i * WIN_WIDTH + j]
				= map->mlx->image_data[i * WIN_WIDTH + j] / 2 | 0x808080;
			j++;
		}
		i++;
	}
}

void	minimap_add_player(t_map *map)
{
	int	x;
	int	y;

	x = map->player_ptr->x * MINIMAP_SCALE + MMAP_OFFSET;
	y = map->player_ptr->y * MINIMAP_SCALE + MMAP_OFFSET;
	draw_rect(map, (t_point){x - MINIMAP_SCALE / 2, y - MINIMAP_SCALE / 2},
		(t_point){x + MINIMAP_SCALE / 2, y + MINIMAP_SCALE / 2}, 0xFF0000);
	minimap_add_angle(map);
}

void	minimap(t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	int				x;
	int				y;

	draw_shadow_box(map, (t_point){MMAP_OFFSET / 2, MMAP_OFFSET / 2},
		(t_point){map->map_width * MINIMAP_SCALE + MMAP_OFFSET + MMAP_OFFSET
		/ 2, map->map_height * MINIMAP_SCALE + MMAP_OFFSET + MMAP_OFFSET / 2});
	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			if (!map->map[i][j])
				break ;
			x = j * MINIMAP_SCALE + MMAP_OFFSET;
			y = i * MINIMAP_SCALE + MMAP_OFFSET;
			if (map->map[i][j] != '1')
				continue ;
			draw_rect(map, (t_point){x, y},
				(t_point){x + MINIMAP_SCALE, y + MINIMAP_SCALE}, 0x000000);
		}
	}
	minimap_add_player(map);
}
