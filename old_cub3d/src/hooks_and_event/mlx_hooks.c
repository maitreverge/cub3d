/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:55:08 by p          #+#    #+#             */
/*   Updated: 2024/06/19 16:45:26 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Handle keyboard events
 * 
 * @param key_code 
 * @param foo 
 * @return int 
 */

int	handle_keyboard_down(int key_code, t_map **foo)
{
	t_map	*map;

	map = *foo;
	if (key_code == KEY_UP || key_code == KEY_W)
		map->player_ptr->go_forward = true;
	else if (key_code == KEY_DOWN || key_code == KEY_S)
		map->player_ptr->go_backward = true;
	else if (key_code == KEY_A)
		map->player_ptr->go_left = true;
	else if (key_code == KEY_D)
		map->player_ptr->go_right = true;
	else if (key_code == KEY_RIGHT)
		map->player_ptr->turn_left = true;
	else if (key_code == KEY_LEFT)
		map->player_ptr->turn_right = true;
	else if (key_code == KEY_ECHAP)
	{
		free_map_struct(map);
		exit(0);
	}
	return (0);
}

/**
 * @brief Handle keyboard events
 * 
 * @param key_code 
 * @param foo 
 * @return int 
 */

int	handle_keyboard_up(int key_code, t_map **foo)
{
	t_map	*map;

	map = *foo;
	if (key_code == KEY_UP || key_code == KEY_W)
		map->player_ptr->go_forward = false;
	else if (key_code == KEY_DOWN || key_code == KEY_S)
		map->player_ptr->go_backward = false;
	else if (key_code == KEY_A)
		map->player_ptr->go_left = false;
	else if (key_code == KEY_D)
		map->player_ptr->go_right = false;
	else if (key_code == KEY_RIGHT)
		map->player_ptr->turn_left = false;
	else if (key_code == KEY_LEFT)
		map->player_ptr->turn_right = false;
	return (0);
}
