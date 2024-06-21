/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:20:13 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 10:50:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;
	size_t				i;

	ps1 = ((const unsigned char *)s1);
	ps2 = ((const unsigned char *)s2);
	i = 0;
	while (i < n)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		i++;
		ps1++;
		ps2++;
	}
	return (0);
}
/*
memcpm ressemble beaucoup a strcmp,
mais resonne en tant que bloc de memoire 
plutot qu'en char*, d'ou la presence de void* declares en const

Ceci implique plusieurs choses :
! 1 Devoir declarer des pointers respectifs
! sur ces deux buffers pour ne pas "y toucher"
! 2 La presence d'un entier positif "n"
! pour devoir s'arreter dans la comparaison

Si une difference est detectee, la fonction renvoie
la difference ASCII des deux valeurs
Les valeurs de retours peuvent donc etre positives
(si on compare s1 == 'a' et s2 == 'A') 
et negatives inversement

Si la fonction retourne 0, ceci indique
que les deux buffers sont identiques, 
dans la mesure de n bytes
*/
