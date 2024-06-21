/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:51:12 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 16:48:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, t_flags flags)
{
	long	nb;
	int		len_nb;

	nb = n;
	len_nb = int_len_zero(n);
	if (!flags.point)
		flags.lenght_print = preci_0_u(nb, len_nb, flags);
	else
		flags.lenght_print = preci_1_u(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_0_u(long nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = preci_0_width_0_u(nb, len_nb);
	else
		flags.lenght_print = preci_0_width_1_u(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_0_width_0_u(long nb, int len_nb)
{
	ft_putnbr(nb);
	return (len_nb);
}

int	preci_0_width_1_u(long nb, int len_nb, t_flags flags)
{
	int	real_width;

	if (flags.minus_sign)
	{
		ft_putnbr(nb);
		real_width = flags.width - len_nb;
		real_width = print_real_width_1(real_width);
		return (len_nb + real_width);
	}
	else
	{
		if (!flags.zero)
		{
			real_width = flags.width - determine_plus(nb, flags) - len_nb;
			real_width = print_real_width_2(real_width, flags);
			ft_putnbr(nb);
		}
		else
		{
			real_width = flags.width - len_nb;
			real_width = print_real_width_2(real_width, flags);
			ft_putnbr(positive_nb(nb));
		}
	}
	return (len_nb + real_width);
}

int	preci_1_u(long nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = preci_1_width_0_u(nb, len_nb, flags);
	else
		flags.lenght_print = preci_1_width_1_u(nb, len_nb, flags);
	return (flags.lenght_print);
}
