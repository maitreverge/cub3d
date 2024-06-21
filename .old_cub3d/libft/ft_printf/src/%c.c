/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %c.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:47:00 by flverge           #+#    #+#             */
/*   Updated: 2023/10/25 13:13:11 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_flags flags)
{
	if (flags.width > 1 && c != '%')
	{
		if (!flags.minus_sign)
		{
			print_width_space(flags.width - 1);
			ft_putchar(c);
		}
		else
		{
			ft_putchar(c);
			print_width_space(flags.width - 1);
		}
		return (flags.width);
	}
	ft_putchar(c);
	return (1);
}
