/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:13 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 14:32:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc_c;
	char			*p_s;
	char			*index;

	p_s = (char *)s;
	uc_c = (unsigned char)c;
	index = NULL;
	while (*p_s != '\0')
	{
		if (*p_s == uc_c)
			index = p_s;
		p_s++;
	}
	if (uc_c == '\0')
		return (p_s);
	else if (index != NULL)
		return (index);
	else
		return (NULL);
}
/*
strrchr cherche la premiere occurence de c dans s

Vu que c est declare en tant que int
et que s est un const char*

Je suis passe par deux variables supplementaires
p_s ==> un pointeur sur le *s
uc_c (unsigned char) de c

Je ne sais pas si c'est mieux de gerer les edges cases
a la fin ou au debut de la fonction... ?!
*/