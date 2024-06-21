/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:27:58 by flverge           #+#    #+#             */
/*   Updated: 2023/11/30 12:43:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*big_chunk(int fd, char *stash)
{
	char	*original_buffer;
	int		return_value_read;

	return_value_read = 1;
	original_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!original_buffer)
		return (NULL);
	while (return_value_read != 0 && ft_strchr_gnl(stash, '\n') == NULL)
	{
		return_value_read = read(fd, original_buffer, BUFFER_SIZE);
		if (return_value_read == -1)
		{
			free(original_buffer);
			return (NULL);
		}
		original_buffer[return_value_read] = '\0';
		stash = ft_strjoin_gnl(stash, original_buffer);
	}
	free(original_buffer);
	return (stash);
}

char	*extract_before_n(char *stash)
{
	char	*temp;
	int		size;

	size = 0;
	if (!stash[size])
		return (NULL);
	while (stash[size] != '\n' && stash[size])
		size++;
	temp = (char *)malloc((size + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	size = 0;
	while (stash[size] != '\n' && stash[size])
	{
		temp[size] = stash[size];
		size++;
	}
	if (stash[size] == '\n')
	{
		temp[size] = stash[size];
		size++;
	}
	temp[size] = '\0';
	return (temp);
}

char	*extract_after_n(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = (char *)malloc((ft_strlen_gnl(stash) - i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (stash[i] != '\0')
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = big_chunk(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	current_line = extract_before_n(stash[fd]);
	stash[fd] = extract_after_n(stash[fd]);
	return (current_line);
}
