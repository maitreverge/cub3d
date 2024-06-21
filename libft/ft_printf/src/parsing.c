/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:31:47 by flverge           #+#    #+#             */
/*   Updated: 2023/11/30 14:23:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	zero_init_struct(void)
{
	t_flags	f;

	f.placeholder = '\0';
	f.hashtag = 0;
	f.plus_sign = 0;
	f.space = 0;
	f.minus_sign = 0;
	f.zero = 0;
	f.width = 0;
	f.width_zeros = 0;
	f.point = 0;
	f.precision = 0;
	f.precision_zeros = 0;
	f.lenght_print = 0;
	return (f);
}

t_flags	first_part_parsing(const char *format, int *i)
{
	t_flags	current_flag;

	current_flag = zero_init_struct();
	while (check_flags(format[*i]))
	{
		if (format[*i] == '#')
			current_flag.hashtag++;
		else if (format[*i] == ' ')
			current_flag.space++;
		else if (format[*i] == '+')
			current_flag.plus_sign++;
		else if (format[*i] == '-')
			current_flag.minus_sign++;
		(*i)++;
	}
	return (current_flag);
}

int	check_placeholder(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

t_flags	split_parsing(int *i, char const *format, t_flags current_flag)
{
	if (check_placeholder(format[*i]) == 1)
	{
		current_flag.placeholder = format[*i];
		return (current_flag);
	}
	current_flag = first_part_parsing(&format[*i], &*i);
	while (format[*i] == '0')
	{
		current_flag.zero++;
		(*i)++;
	}
	if (format[*i] != '.' && ft_isdigit_pf(format[*i]))
	{
		while (format[*i] == '0')
		{
			current_flag.width_zeros++;
			(*i)++;
		}
		current_flag.width = width_or_precision(&format[*i]);
		while (ft_isdigit_pf(format[*i]))
			(*i)++;
	}
	return (current_flag);
}

t_flags	turbo_parsing(const char *format)
{
	t_flags	current_flag;
	int		i;

	current_flag = zero_init_struct();
	i = 0;
	current_flag = split_parsing(&i, &format[i], current_flag);
	while (format[i] == '.')
	{
		current_flag.point++;
		i++;
	}
	if (current_flag.point && ft_isdigit_pf(format[i]))
	{
		while (format[i] == '0')
		{
			current_flag.precision_zeros++;
			i++;
		}
		current_flag.precision = width_or_precision(&format[i]);
		while (ft_isdigit_pf(format[i]))
			i++;
	}
	current_flag.placeholder = format[i];
	return (current_flag);
}
