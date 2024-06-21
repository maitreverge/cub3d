/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:33 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 13:42:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	placeholder_behaviour(t_flags flags, va_list args)
{
	int	result;

	result = 0;
	if (flags.placeholder == '%')
		result = print_char('%', flags);
	else if (flags.placeholder == 'c')
		result = print_char(va_arg(args, int), flags);
	else if (flags.placeholder == 's')
		result = print_string(va_arg(args, char *), flags);
	else if (flags.placeholder == 'p')
		result = print_adress(va_arg(args, unsigned long), flags);
	else if (flags.placeholder == 'd' || flags.placeholder == 'i')
		result = print_i_and_d_reload(va_arg(args, int), flags);
	else if (flags.placeholder == 'u')
		result = print_unsigned(va_arg(args, unsigned int), flags);
	else if (flags.placeholder == 'x')
		result = print_x(va_arg(args, unsigned int), flags);
	else if (flags.placeholder == 'X')
		result = print_upx(va_arg(args, unsigned int), flags);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_printf;
	t_flags	current_flag;

	va_start(args, format);
	i = 0;
	len_printf = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			current_flag = turbo_parsing(&format[i + 1]);
			len_printf += placeholder_behaviour(current_flag, args);
			i += count_flags(current_flag);
		}
		else
		{
			ft_putchar(format[i]);
			len_printf++;
		}
		i++;
	}
	va_end(args);
	return (len_printf);
}
