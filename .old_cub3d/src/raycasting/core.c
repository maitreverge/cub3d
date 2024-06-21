/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:43:22 by p          #+#    #+#             */
/*   Updated: 2024/04/24 13:20:59 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_player_angle(t_player *player, double fps)
{
	if (player->turn_left)
		player->angle -= SPEED_ROTATION / fps;
	if (player->turn_right)
		player->angle += SPEED_ROTATION / fps;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	if (player->angle < 0)
		player->angle += 2 * M_PI;
}

void	update_player_schizophrenia(t_map *map, t_player *player,
		t_player *tmp, double fps)
{
	if (tmp->go_left)
	{
		tmp->x -= sin(tmp->angle + M_PI_2) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp->y][(int) tmp->x] == '1')
			tmp->x = player->x;
		tmp->y -= cos(tmp->angle + M_PI_2) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp->y][(int) tmp->x] == '1')
			tmp->y = player->y;
	}
	if (tmp->go_right)
	{
		tmp->x += sin(tmp->angle + M_PI_2) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp->y][(int) tmp->x] == '1')
			tmp->x = player->x;
		tmp->y += cos(tmp->angle + M_PI_2) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp->y][(int) tmp->x] == '1')
			tmp->y = player->y;
	}
}

void	update_player_position(t_map *map, t_player *player, double fps)
{
	t_player	tmp;

	tmp = *player;
	if (tmp.go_backward)
	{
		tmp.x -= sin(tmp.angle) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp.y][(int) tmp.x] == '1')
			tmp.x = player->x;
		tmp.y -= cos(tmp.angle) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp.y][(int) tmp.x] == '1')
			tmp.y = player->y;
	}
	if (tmp.go_forward)
	{
		tmp.x += sin(tmp.angle) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp.y][(int) tmp.x] == '1')
			tmp.x = player->x;
		tmp.y += cos(tmp.angle) * SPEED_MOVEMENT / fps;
		if (map->map[(int) tmp.y][(int) tmp.x] == '1')
			tmp.y = player->y;
	}
	update_player_schizophrenia(map, player, &tmp, fps);
	*player = tmp;
	update_player_angle(player, fps);
}

int	main_loop(t_map *map)
{
	double	load;
	double	fps;

	fps = stabilize_fps(&load);
	update_player_position(map, map->player_ptr, fps);
	raycasting(map, map->player_ptr);
	minimap(map);
	draw_fps(map, fps, load);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->window,
		map->mlx->image, 0, 0);
	return (0);
}

/**
 * @brief Starting function for raycasting
 * 
 * @param foo 
 */
void	cub3d(t_map **foo)
{
	t_player	player;
	t_map		*map;

	map = *foo;
	ft_memset(&player, 0, sizeof(t_player));
	player.angle = get_start_angle(map->player_start_axis);
	map->player_ptr = &player;
	player.x = map->player_start_x;
	player.y = map->player_start_y;
	texture_loadall(map);
	map->font = font_load("textures/font.psf");
	if (!map->font)
		custom_exit(map, "Failed to load font");
	mlx_hook(map->mlx->window, X_CROSS, 1L << 0, &free_cross, &map);
	mlx_hook(map->mlx->window, KEY_PRESS, 1L << 0, &handle_keyboard_down, &map);
	mlx_hook(map->mlx->window, KEY_RELEASE, 1L << 1, &handle_keyboard_up, &map);
	mlx_loop_hook(map->mlx->mlx, &main_loop, map);
	mlx_loop(map->mlx->mlx);
}
