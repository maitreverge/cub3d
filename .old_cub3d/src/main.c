/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:59:23 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 15:44:45 by p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Wrapper function of `parse_map`, checks if the parsing executed well.
 * 
 * @param av 
 * @param map 
 * @return true 
 * @return false 
 */
static bool	correct_parsing(char **av, t_map **map)
{
	if (ft_strlen(av[1]) < 4
		|| ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		error_message("Map file must be a .cub file.");
		return (false);
	}
	*map = parse_map(av[1], map);
	return (true);
}

/**
 * @brief Checks arguments ac/av + safely tries to access the map at av[1].
 * 
 * @param ac 
 * @param av 
 * @return true 
 * @return false 
 */
static bool	correct_args(int ac, char **av)
{
	int	fd_map;

	if (incorrect_window_size())
		return (false);
	if (ac != 2)
	{
		if (ac == 1)
			error_message("Missing Argument");
		else
			error_message("Too many argments");
		print_usage();
		return (false);
	}
	fd_map = open(av[1], O_RDONLY);
	if (fd_map == -1)
	{
		error_message("Can't find / open the map.");
		print_usage();
		close(fd_map);
		return (false);
	}
	close(fd_map);
	return (true);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	if (correct_args(ac, av) && correct_parsing(av, &map))
		cub3d(&map);
	return (1);
}
