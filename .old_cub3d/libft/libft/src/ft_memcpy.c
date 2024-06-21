/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:20:19 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 10:11:22 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/*
memcpy est une fonction de copie d'un buffer src vers un void dst

Pour plus de simplicite, j'ai decide de prendre le parti de caster
ces deux buffers en char*, ce qui reviens a copier byte par byte

Le parti pris du prototypage de la fonction en void* nous oblige egalement
a avoir un entier positif "n", qui deviens un element de la seule boucle while
*/
