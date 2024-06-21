/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %x_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:51:32 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 14:10:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int n, t_flags flags)
{
	unsigned long	nb;
	int				len_nb;
	int				hashtag;

	nb = n;
	len_nb = intlen_hexa_zero(n);
	hashtag = 0;
	if (!flags.point)
		flags.lenght_print = preci_0_x(nb, len_nb, flags, hashtag);
	else
		flags.lenght_print = preci_1_x(nb, len_nb, flags, hashtag);
	return (flags.lenght_print);
}

int	preci_1_x(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	int	real_prec;

	real_prec = flags.precision - len_nb;
	if (real_prec < 0)
		real_prec = 0;
	if (!flags.width)
		flags.lenght_print = preci_1_w_0_x(nb, len_nb, flags, hashtag);
	else
		flags.lenght_print = preci_1_w_1_x(nb, len_nb, flags, real_prec);
	return (flags.lenght_print);
}

int	preci_1_w_0_x(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb == 0 && flags.precision == 0)
		return (0);
	real_precision = flags.precision - len_prec;
	hashtag = print_hashtag_low(flags, nb);
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	putnbr_hexa(nb, 'x');
	return (len_nb + hashtag + real_precision);
}

int	preci_1_w_1_x(unsigned long nb, int len_nb, t_flags f, int real_prec)
{
	int	real_width;

	real_width = f.width - determine_hashtag(f, nb) - len_nb - real_prec;
	if (real_width < 0)
		real_width = 0;
	if (!f.precision && !nb)
		return (zero_case(f));
	if (!f.minus_sign)
	{
		print_width_space(real_width);
		print_hashtag_low(f, nb);
		if (real_prec > 0)
			print_zero(real_prec);
		putnbr_hexa(nb, 'x');
	}
	else
	{
		print_hashtag_low(f, nb);
		if (real_prec > 0)
			print_zero(real_prec);
		putnbr_hexa(nb, 'x');
		print_width_space(real_width);
	}
	return (len_nb + real_width + real_prec);
}
