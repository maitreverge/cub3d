/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:24:09 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 15:45:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	int		i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	buffer = ft_calloc(len_s + 1, 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s, len_s);
	while (s[i])
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	return (buffer);
}
/*
A la meme maniere que striteri
strmapi fonctionne de la meme facon, a la seule difference
que strmapi cree un nouveau buffer sur lequel la foncion char (*f)
va s'appliquer

(contrairement a striteri ou les changement de la fonction void
s'appliquent au buffer original)
*/
