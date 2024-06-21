/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:27:45 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 12:33:11 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= (-1);
	}
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	int_len_zero(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= (-1);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int	i;
	char			*str;

	str = my_calloc(n + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int	print_plus_or_space(long nb, t_flags flags)
{
	int	plus_sign;
	int	space_sign;

	plus_sign = 0;
	space_sign = 0;
	if (flags.plus_sign && nb >= 0 && !flags.space)
	{
		plus_sign++;
		ft_putchar('+');
	}
	else if (flags.space && !flags.plus_sign && nb >= 0)
	{
		space_sign++;
		ft_putchar(' ');
	}
	return (plus_sign + space_sign);
}
