/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %x_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:23 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 14:11:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	preci_0_x(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	if (!flags.width)
		flags.lenght_print = preci_0_w_0_x(nb, len_nb, flags, hashtag);
	else
		flags.lenght_print = preci_0_w_1_x(nb, len_nb, flags, hashtag);
	return (flags.lenght_print);
}

int	preci_0_w_0_x(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	hashtag = print_hashtag_low(flags, nb);
	putnbr_hexa(nb, 'x');
	return (len_nb + hashtag);
}

int	preci_0_w_1_x(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	int	real_width;

	if (flags.minus_sign)
	{
		hashtag = print_hashtag_low(flags, nb);
		putnbr_hexa(nb, 'x');
		real_width = flags.width - hashtag - len_nb;
		real_width = print_real_width_1(real_width);
		return (len_nb + hashtag + real_width);
	}
	if (!flags.zero)
	{
		real_width = flags.width - determine_hashtag(flags, nb) - len_nb;
		real_width = print_real_width_2(real_width, flags);
		hashtag = print_hashtag_low(flags, nb);
		putnbr_hexa(nb, 'x');
	}
	else
	{
		hashtag = print_hashtag_low(flags, nb);
		real_width = flags.width - hashtag - len_nb;
		real_width = print_real_width_2(real_width, flags);
		putnbr_hexa(nb, 'x');
	}
	return (len_nb + hashtag + real_width);
}
