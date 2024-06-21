/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:18:39 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 09:59:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_lenght(long n)
{
	int	total_lenght;

	if (n < 0)
	{
		total_lenght = 2;
		n = n * (-1);
	}
	else
		total_lenght = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		total_lenght++;
	}
	return (total_lenght);
}
/*
alloc_lenght check la longueur du chiffre
10 => 1
999 => 2
ect...
et rajoute +1 si le nombre est negatif pour
laisser un emplacement de malloc supplementaire
pour le '-'
*/

static void	check_neg(long *nbr, char *buffer)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * (-1);
		buffer[0] = '-';
	}
}
/*
check_neg a pour seul role d'allouer le char '-'
au tout debut du buffer si le nombre est negatif
*/

char	*ft_itoa(int n)
{
	char	*buffer;
	int		lenght;
	int		i;
	long	nbr;

	nbr = n;
	lenght = alloc_lenght(nbr);
	buffer = malloc(lenght + 1);
	if (!buffer)
		return (NULL);
	check_neg(&nbr, buffer);
	i = lenght;
	if (nbr == 0)
		buffer[i - 1] = '0';
	while (nbr > 0)
	{
		buffer[i - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	buffer[lenght] = '\0';
	return (buffer);
}
/*
ft_itoa transforme un int en char*
pour plus de simplicite de conversion, l'attribution
d'un long corrige le probleme de limitation INT_MIN * -1
qui depasse donc la limite INT_MAX.
L'allocation correcte une fois effectuee avec la sous-fonction alloc_lenght

! 1 => On attribue un '-' au debut du buffer si n < 0
! 2 => On check si n == 0 pour ecarter ce cas special
! 3 => puis on remplit le buffer en marche arriere avec un modulo 10 
*/
