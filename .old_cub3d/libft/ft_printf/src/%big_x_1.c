/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %big_x_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:55:46 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 14:01:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_upx(unsigned int n, t_flags f)
{
	unsigned long	nb;
	int				len_nb;
	int				hashtag;

	nb = n;
	len_nb = intlen_hexa_zero(n);
	hashtag = 0;
	if (!f.point)
		f.lenght_print = preci_0_upx(nb, len_nb, f, hashtag);
	else
		f.lenght_print = preci_1_upx(nb, len_nb, f, hashtag);
	return (f.lenght_print);
}

int	preci_1_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	int	real_prec;

	real_prec = f.precision - len_nb;
	if (real_prec < 0)
		real_prec = 0;
	if (!f.width)
		f.lenght_print = preci_1_w_0_upx(nb, len_nb, f, hashtag);
	else
		f.lenght_print = preci_1_w_1_upx(nb, len_nb, f, real_prec);
	return (f.lenght_print);
}

int	preci_1_w_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb == 0 && f.precision == 0)
		return (0);
	real_precision = f.precision - len_prec;
	hashtag = print_hashtag_up(f, nb);
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	putnbr_hexa(nb, 'X');
	return (len_nb + hashtag + real_precision);
}

int	preci_1_w_1_upx(unsigned long nb, int len_nb, t_flags f, int real_prec)
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
		print_hashtag_up(f, nb);
		if (real_prec > 0)
			print_zero(real_prec);
		putnbr_hexa(nb, 'X');
	}
	else
	{
		print_hashtag_up(f, nb);
		if (real_prec > 0)
			print_zero(real_prec);
		putnbr_hexa(nb, 'X');
		print_width_space(real_width);
	}
	return (len_nb + real_width + real_prec);
}
