/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:34:00 by p          #+#    #+#             */
/*   Updated: 2024/06/19 16:46:48 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// if we are in the corner of 2 textures, we choose
// the one to avoid glitches
int	determine_wall(int wall, double a, double b, double *c)
{
	if (fabs(a - b) < 0.02 || fabs(a - b) > 0.98)
	{
		*c = t(wall == 0 || wall == 2, b, a);
		return (wall);
	}
	if (fabs(a - round(a)) < fabs(b - round(b)))
	{
		*c = b;
		return (t(b > a, 0, 2));
	}
	*c = a;
	return (t(b > a, 1, 3));
}

// Correct fish eye effect by using the cosinus of the angle
// between the player and the wall
double	get_distance_to_wall(t_map *map, double angle,
		double *texture_x, int *wall)
{
	double	distance_to_wall;
	double	texture_y;
	double	eye_x;
	double	eye_y;

	eye_x = sin(angle);
	eye_y = cos(angle);
	distance_to_wall = 0;
	while (distance_to_wall < 100)
	{
		distance_to_wall += 0.01;
		*texture_x = map->player_ptr->x + eye_x * distance_to_wall;
		texture_y = map->player_ptr->y + eye_y * distance_to_wall;
		if (map->map[(int) texture_y][(int) *texture_x] == '1')
		{
			*texture_x = *texture_x - (int) *texture_x;
			texture_y = texture_y - (int) texture_y;
			*wall = determine_wall(*wall, *texture_x, texture_y, texture_x);
			distance_to_wall *= cos(map->player_ptr->angle - angle);
			return (distance_to_wall);
		}
	}
	return (INFINITY);
}

int	do_raycasting(t_map *map, t_player *player, int x, int wall)
{
	double	distance_to_wall;
	double	texture_x;
	int		ceiling;
	int		floor;
	int		y;

	distance_to_wall = get_distance_to_wall(map, player->angle - (FOV / 2)
			+ (FOV * x / WIN_WIDTH), &texture_x, &wall);
	ceiling = (WIN_HEIGHT / 2) - WIN_HEIGHT / distance_to_wall;
	floor = WIN_HEIGHT - ceiling;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y >= ceiling && y < floor)
			map->mlx->image_data[y * WIN_WIDTH + (WIN_WIDTH - x)] = map->textures[wall]->addr[
				(int)(((y - ceiling) / (double)(floor - ceiling))
					*map->textures[wall]->height)*map->textures[wall]->width
				+ (int)(texture_x * map->textures[wall]->width)];
		else if (y < ceiling)
			map->mlx->image_data[y * WIN_WIDTH + (WIN_WIDTH - x)] = map->ceiling_color;
		else
			map->mlx->image_data[y * WIN_WIDTH + (WIN_WIDTH - x)] = map->floor_color;
	}
	return (wall);
}

// restrict is a keyword that tells the compiler that the pointer is not aliased
// it can be used to optimize the code (no pointer reloading)
void	raycasting(t_map *restrict map, t_player *restrict player)
{
	int	wall;
	int	x;

	wall = 0;
	x = 0;
	while (x < WIN_WIDTH)
	{
		wall = do_raycasting(map, player, x, wall);
		x++;
	}
}

double	stabilize_fps(double *load)
{
	static double	last_frame_time = 0;
	double			current_time;
	double			first_fps;
	double			fps;

	current_time = get_us();
	first_fps = 1000000.0 / (current_time - last_frame_time);
	if (first_fps > FPS_LIMIT)
	{
		usleep(1.0 / FPS_LIMIT * 1000000.0 - (current_time - last_frame_time));
		current_time = get_us();
		fps = 1000000.0 / (current_time - last_frame_time);
	}
	else
		fps = first_fps;
	last_frame_time = current_time;
	if (load)
		*load = 100 * fps / first_fps;
	return (fps);
}
