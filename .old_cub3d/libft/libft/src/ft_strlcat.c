/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:23:29 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 12:46:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	j = ft_strlen(dst);
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dest)
		return (dstsize + len_src);
	while (i < (dstsize - len_dest - 1) && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_dest + len_src);
}
/*
strlcat est une fonction qui fait 2 actions en une :
elle copie le contennu de src a la fin de dst
en copiant manuellement un '\0' a la fin de dest
(d'ou dstsize - len_dest -1 dans la boucle while)

J'ai utilise deux indexs de strlen(dst) pour :
1 => Constamment garder la taille de dst (qui sert d'argument pour while)
2 => En tant qu'index qui sert lors de la copie

La fonction retourne le nombre de char qu'elle
a pu copier
*/
