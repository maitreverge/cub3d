/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %big_x_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:40:12 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 14:05:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	preci_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	if (!f.width)
		f.lenght_print = preci_0_w_0_upx(nb, len_nb, f, hashtag);
	else
		f.lenght_print = preci_0_w_1_upx(nb, len_nb, f, hashtag);
	return (f.lenght_print);
}

int	preci_0_w_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	hashtag = print_hashtag_up(f, nb);
	putnbr_hexa(nb, 'X');
	return (len_nb + hashtag);
}

int	preci_0_w_1_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	int	real_width;

	if (f.minus_sign)
	{
		hashtag = print_hashtag_up(f, nb);
		putnbr_hexa(nb, 'X');
		real_width = f.width - hashtag - len_nb;
		real_width = print_real_width_1(real_width);
		return (len_nb + hashtag + real_width);
	}
	if (!f.zero)
	{
		real_width = f.width - determine_hashtag(f, nb) - len_nb;
		real_width = print_real_width_2(real_width, f);
		hashtag = print_hashtag_up(f, nb);
		putnbr_hexa(nb, 'X');
	}
	else
	{
		hashtag = print_hashtag_up(f, nb);
		real_width = f.width - hashtag - len_nb;
		real_width = print_real_width_2(real_width, f);
		putnbr_hexa(nb, 'X');
	}
	return (len_nb + hashtag + real_width);
}
