/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %i_d_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:19:10 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 16:26:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	preci_0(long nb, int len_nb, t_flags flags, int sp_pl)
{
	if (!flags.width)
		flags.lenght_print = preci_0_width_0(nb, len_nb, flags, sp_pl);
	else
		flags.lenght_print = preci_0_width_1(nb, len_nb, flags, sp_pl);
	return (flags.lenght_print);
}

int	preci_0_width_0(long nb, int len_nb, t_flags flags, int sp_pl)
{
	sp_pl = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	return (len_nb + sp_pl);
}

int	yes_minus(long nb, int len_nb, int sp_pl, t_flags flags)
{
	int	real_width;

	sp_pl = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	real_width = flags.width - sp_pl - len_nb;
	real_width = print_real_width_1(real_width);
	return (len_nb + sp_pl + real_width);
}

int	preci_0_width_1(long nb, int len_nb, t_flags flags, int sp_pl)
{
	int	real_width;

	if (flags.minus_sign)
		return (yes_minus(nb, len_nb, sp_pl, flags));
	if (!flags.zero)
	{
		real_width = flags.width - determine_plus(nb, flags) - len_nb;
		real_width = print_real_width_2(real_width, flags);
		sp_pl = print_plus_or_space(nb, flags);
		ft_putnbr(nb);
	}
	else
	{
		sp_pl = print_plus_or_space(nb, flags);
		if (nb < 0)
			ft_putchar('-');
		real_width = flags.width - sp_pl - len_nb;
		real_width = print_real_width_2(real_width, flags);
		ft_putnbr(positive_nb(nb));
	}
	return (len_nb + sp_pl + real_width);
}

void	yes_min(long nb, int real_width, int real_precision, t_flags f)
{
	print_plus_or_space(nb, f);
	if (nb < 0)
		ft_putchar('-');
	if (real_precision > 0)
		print_zero(real_precision);
	ft_putnbr(positive_nb(nb));
	print_width_space(real_width);
}
