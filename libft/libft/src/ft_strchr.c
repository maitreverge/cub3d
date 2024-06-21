/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:22:50 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 12:27:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*p_s;
	unsigned char	uc_c;

	p_s = ((char *)s);
	uc_c = ((unsigned char)c);
	while (*p_s != '\0')
	{
		if (*p_s == uc_c)
			return (p_s);
		p_s++;
	}
	if (uc_c == '\0')
		return (p_s);
	else
		return (NULL);
}
/*
strchr va rechercher dans un buffer s la presence du char c
(qui est en realite un int pour des soucis de
compatibilite)

J'ai utilise deux variables pour :
! 1 : Convertir le int en char
! 2 : creer un pointer sur s pour "contourner"
! le mot clef "const" qui nous empeche de modifier le buffer
*/