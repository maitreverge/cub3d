/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:05 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 14:29:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if ((len == 0 && !big) || (len == 0 && !little))
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	else
	{
		while (big[i] != '\0' && i < len)
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] != '\0'
				&& (i + j) < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
			}
			i++;
		}
		return (NULL);
	}
}
/*
strnstr a pour but de rechercher little dans big
et se met a le rechercher dans un maximum de len
*/