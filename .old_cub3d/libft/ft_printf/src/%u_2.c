/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:46:54 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 16:48:28 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	preci_1_width_0_u(long nb, int len_nb, t_flags flags)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb < 0)
		len_prec -= 1;
	if (nb == 0 && flags.precision == 0)
		return (0);
	real_precision = flags.precision - len_prec;
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	ft_putnbr(positive_nb(nb));
	return (len_nb + real_precision);
}

int	preci_1_width_1_u(long nb, int len_nb, t_flags flags)
{
	int	real_width;
	int	real_prec;
	int	len_prec;

	len_prec = len_nb;
	if (nb < 0)
		len_prec -= 1;
	real_prec = flags.precision - len_prec;
	if (real_prec < 0)
		real_prec = 0;
	real_width = flags.width - determine_plus(nb, flags) - len_nb - real_prec;
	if (real_width < 0)
		real_width = 0;
	if (!flags.precision && !nb)
		return (zero_case(flags));
	if (!flags.minus_sign)
		no_minus_u(nb, real_width, real_prec);
	else
		yes_minus_u(nb, real_width, real_prec);
	return (len_nb + real_width + real_prec);
}

void	no_minus_u(long nb, int real_width, int real_precision)
{
	print_width_space(real_width);
	if (real_precision > 0)
		print_zero(real_precision);
	ft_putnbr(positive_nb(nb));
}

void	yes_minus_u(long nb, int real_width, int real_precision)
{
	if (real_precision > 0)
		print_zero(real_precision);
	ft_putnbr(positive_nb(nb));
	print_width_space(real_width);
}
