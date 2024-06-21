/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:31:28 by p          #+#    #+#             */
/*   Updated: 2024/04/24 14:05:26 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_rect(t_map *map, t_point start, t_point end, uint32_t color)
{
	unsigned int	i;
	unsigned int	j;

	i = start.y;
	while (i < end.y)
	{
		j = start.x;
		while (j < end.x)
		{
			map->mlx->image_data[i * WIN_WIDTH + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_fps(t_map *map, double new_fps, double new_load)
{
	static t_fps	fps = {0, 0, 0};
	double			coef;
	char			str[20];

	if (fps.frame_count == 0)
	{
		fps.fps = new_fps;
		fps.load = new_load;
		fps.frame_count++;
	}
	else
	{
		if (fps.frame_count > 99)
			fps.frame_count = 99;
		coef = (double) fps.frame_count / 100;
		fps.fps = fps.fps * coef + new_fps * (1 - coef);
		fps.load = fps.load * coef + new_load * (1 - coef);
		fps.frame_count += 10;
	}
	draw_shadow_box(map, (t_point){WIN_WIDTH - 100, MMAP_OFFSET / 2},
		(t_point){WIN_WIDTH - MMAP_OFFSET / 2, 45 + MMAP_OFFSET / 2});
	snprintf(str, 20, "CPU% 4i", (int) fps.load);
	font_print(map, WIN_WIDTH - 95, MMAP_OFFSET / 2 + 2, str);
	snprintf(str, 20, "FPS% 4i", (int) fps.fps);
	font_print(map, WIN_WIDTH - 95, MMAP_OFFSET + 15, str);
}
