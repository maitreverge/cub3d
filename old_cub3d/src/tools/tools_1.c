/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:36:07 by p          #+#    #+#             */
/*   Updated: 2024/04/24 14:53:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*ft_rcalloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
		ft_memcpy(new_ptr, ptr, old_size);
	ft_memset(new_ptr + old_size, 0, new_size - old_size);
	free(ptr);
	return (new_ptr);
}

char	*get_line(int fd)
{
	char	*line;
	char	c;
	int		i;

	line = ft_rcalloc(NULL, 0, 1);
	i = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
			return (line);
		line = ft_rcalloc(line, i, i + 2);
		line[i] = c;
		i++;
	}
	if (i)
		return (line);
	free(line);
	return (NULL);
}

int	t(int a, int b, int c)
{
	if (a == 1)
		return (b);
	return (c);
}
