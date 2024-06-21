/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:32 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 16:04:48 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	size_t		trimmed_len;
	char		*buffer;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	trimmed_len = end - start + 1;
	buffer = ft_calloc(trimmed_len + 1, 1);
	if (!buffer)
		return (NULL);
	ft_strncpy(buffer, start, trimmed_len);
	return (buffer);
}
/*
strtrim "rogne" de s1 la chaine set,
avant et apres

! Etape 1 : regarder si l'une ou l'autre existe vraiment

! Etape 2 : Parcourir une premiere fois la chaine
en marche avant, et s'arreter des que strchr ne 
rencontre plus la chaine set dans s1

!Etape 3 : Parcourir la chaine mais cette fois en marche arriere
pour faire la meme chose 

! Etape 4 : allouer avec calloc la taille finale (end - start + 1)

! Etape 5 : copier avec strncpy, qui garantie une copie avec un '\0'
*/
