/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:23:05 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 12:31:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	buffer = (char *)malloc(len_s1 + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, len_s1);
	buffer[len_s1] = '\0';
	return (buffer);
}
/*
strdup est une fonction qui copie
dans une nouveau buffer le buffer s1 passe en parametre

Il est de la responsabilite de l'utilisateur de devoir
free le buffer dans la fonction qui appelle strdup

Il est egalement imperatif de mettre un '\0'
a la fin du buffer, car memcpy ne le fait pas
(car c'est une fonction qui raisonne avec un void*,
et non un char*)
*/
