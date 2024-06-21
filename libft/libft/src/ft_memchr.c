/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:20:07 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 10:47:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*p_s;
	unsigned char	uc_c;

	p_s = ((unsigned char *)s);
	uc_c = ((unsigned char)c);
	i = 0;
	while (i < n)
	{
		if (*p_s == uc_c)
			return (p_s);
		i++;
		p_s++;
	}
	return (NULL);
}
/*
memchr recherche la premiere occurence d'un char
dans une chaine de caractere
la presence d'un void*, d'un char sous forme
de int nous contraint a faire deux choses :
*/

/*
! Declarer un pointer sur ce void* declare en const
! pour se balader dessus via un pointer
! Declarer le parametre c en tant que unsigned char
! pour plus de coherence avec le point precedent
La fonction retourne l'emplacement du char en question, a savoir p_s
sinon NULL
*/
