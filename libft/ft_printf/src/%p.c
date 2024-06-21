/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:01:58 by flverge           #+#    #+#             */
/*   Updated: 2023/11/30 14:20:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	empty_adress(char *nul_str, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = no_width(nul_str);
	else
		flags.lenght_print = yes_width(nul_str, flags);
	return (flags.lenght_print);
}

int	yes_width_hexa(char *prefix, t_flags flags, unsigned long nb)
{
	int	len_prefix;
	int	len_nb;
	int	total_len;

	len_prefix = ft_strlen_pf(prefix);
	len_nb = intlen_hexa(nb);
	total_len = len_nb + len_prefix;
	if (flags.minus_sign)
	{
		ft_putstr(prefix);
		putnbr_hexa(nb, 'x');
		print_width_space(flags.width - total_len);
	}
	else
	{
		print_width_space(flags.width - total_len);
		ft_putstr(prefix);
		putnbr_hexa(nb, 'x');
	}
	return (total_len + pos_width(flags.width, total_len));
}

int	print_adress(unsigned long nb, t_flags flags)
{
	char	*prefix;

	if (nb == 0)
		return (empty_adress("(nil)", flags));
	prefix = "0x";
	if (!flags.width)
	{
		ft_putstr(prefix);
		putnbr_hexa(nb, 'x');
		flags.lenght_print = (intlen_hexa(nb) + ft_strlen_pf(prefix));
	}
	else
		flags.lenght_print = yes_width_hexa(prefix, flags, nb);
	return (flags.lenght_print);
}
