/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:04:48 by flverge           #+#    #+#             */
/*   Updated: 2024/06/22 13:05:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d>

/**
 * @brief Print usage to stdout in case of incorrect arguments ac/av.
 * 
 */
void	print_usage(void)
{
	printf("Usage :\n");
	printf(GREEN BOLD"./cub3d   "RESET);
	printf(YELLOW BOLD"<path_to_valid_map>\n"RESET);
}