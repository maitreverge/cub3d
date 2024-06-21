/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %i_d_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:19:10 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 16:26:31 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i_and_d_reload(int n, t_flags flags)
{
	long	nb;
	int		len_nb;
	int		sp_pl;

	nb = n;
	len_nb = int_len_zero(n);
	sp_pl = 0;
	if (!flags.point)
		flags.lenght_print = preci_0(nb, len_nb, flags, sp_pl);
	else
		flags.lenght_print = preci_1(nb, len_nb, flags, sp_pl);
	return (flags.lenght_print);
}

int	preci_1(long nb, int len_nb, t_flags flags, int sp_pl)
{
	if (!flags.width)
		flags.lenght_print = preci_1_width_0(nb, len_nb, flags, sp_pl);
	else
		flags.lenght_print = preci_1_width_1(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_1_width_0(long nb, int len_nb, t_flags flags, int sp_pl)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb < 0)
		len_prec -= 1;
	if (nb == 0 && flags.precision == 0)
		return (0);
	real_precision = flags.precision - len_prec;
	sp_pl = print_plus_or_space(nb, flags);
	if (nb < 0)
		ft_putchar('-');
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	ft_putnbr(positive_nb(nb));
	return (len_nb + sp_pl + real_precision);
}

int	preci_1_width_1(long nb, int len_nb, t_flags f)
{
	int	real_width;
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb < 0)
		len_prec -= 1;
	real_precision = f.precision - len_prec;
	if (real_precision < 0)
		real_precision = 0;
	real_width = f.width - determine_plus(nb, f) - len_nb - real_precision;
	if (real_width < 0)
		real_width = 0;
	if (!f.precision && !nb)
		return (zero_case(f));
	if (!f.minus_sign)
		no_min(nb, real_width, real_precision, f);
	else
		yes_min(nb, real_width, real_precision, f);
	return (len_nb + real_width + real_precision);
}

void	no_min(long nb, int real_width, int real_precision, t_flags f)
{
	print_width_space(real_width);
	if (nb < 0)
		ft_putchar('-');
	print_plus_or_space(nb, f);
	if (real_precision > 0)
		print_zero(real_precision);
	ft_putnbr(positive_nb(nb));
}
