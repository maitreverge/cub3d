/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:21:52 by flverge           #+#    #+#             */
/*   Updated: 2024/04/24 15:08:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	polarity;
	int	result;

	i = 0;
	polarity = 1;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			polarity *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = (10 * result) + (str[i] - '0');
		if (result < 0)
			return (-1);
		i++;
	}
	return (polarity * result);
}
/* 
Ft_atoi prends une chaine de caracteres en paramettre
et renvoie un nombre int en checkant
la polarite
la presence d'espaces avec ft_isspace

*/
