/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:20:26 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 10:49:39 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_ptr;
	size_t		i;
	char		*dest_ptr;

	dest_ptr = (char *)dst;
	src_ptr = (const char *)src;
	if (dest_ptr > src_ptr)
	{
		i = len;
		while (i > 0)
		{
			--i;
			dest_ptr[i] = src_ptr[i];
		}
	}
	else if (dest_ptr < src_ptr)
	{
		i = 0;
		while (i < len)
		{
			dest_ptr[i] = src_ptr[i];
			++i;
		}
	}
	return (dst);
}

/*
IMPORTANT :
memmove ≠ memcpy
memcpy et memmove ont toutes deux le meme but
: copier le contennu
d'un buffer src vers un buffer dest.
La difference reside dans le fait que memcpy
part du principe que les deux buffers
n'overlap pas, tandis que memmove oui.
*/

/*
Cette derniere est donc logiquement plus securisee,
nottament sur les petits systemes
a faible memoire, et cela implique de devoir considerer 2 scenarios

! SCENARIO 1 : Les deux blocs de memoire se chevauchent
C'est donc le premier cas implemente dans ma fonction
si le pointer vers dest est superieur a celui de src
Dans ce cas precis, pour eviter de detruire src, nous devont copier
en "marche arriere" de maniere non destructive
*/

/*
! SCENARIO 2 : Les deux blocs de memoire ne se chevauchent pas
Dans ce cas, l'implementation est similaire a memcpy,
une simple copie avec un index qui incremente em i++
*/
