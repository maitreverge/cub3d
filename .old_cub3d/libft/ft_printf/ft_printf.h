/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/12/06 15:11:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef struct s_flags
{
	char	placeholder;
	int		hashtag;
	int		plus_sign;
	int		space;
	int		minus_sign;
	int		zero;
	int		width;
	int		width_zeros;
	int		point;
	int		precision;
	int		precision_zeros;
	int		lenght_print;
}	t_flags;

int		ft_printf(const char *format, ...);
int		placeholder_behaviour(t_flags flags, va_list args);

// parsing functions
t_flags	turbo_parsing(const char *format);
t_flags	split_parsing(int *i, char const *format, t_flags current_flag);
t_flags	zero_init_struct(void);
t_flags	first_part_parsing(const char *format, int *i);
t_flags	cleaning_parsing(t_flags f);
int		check_placeholder(char c);

// %c
int		print_char(char c, t_flags flags);

// %s
int		print_string(char *str, t_flags flags);
int		empty_string(char *nul_str, t_flags flags);
int		no_width(char *nul_str);
int		yes_width(char *nul_str, t_flags flags);

// %p
int		print_adress(unsigned long nb, t_flags flags);
int		yes_width_hexa(char *prefix, t_flags flags, unsigned long nb);
int		empty_adress(char *nul_str, t_flags flags);

// %i && %d
int		print_i_and_d_reload(int nb, t_flags flags);
int		preci_0(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_0_width_0(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_0_width_1(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_1(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_1_width_0(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_1_width_1(long nb, int len_nb, t_flags flags);
int		yes_minus(long nb, int len_nb, int sp_pl, t_flags flags);
void	no_min(long nb, int real_width, int real_precision, t_flags f);
void	yes_min(long nb, int real_width, int real_precision, t_flags f);

// %u
int		print_unsigned(unsigned int n, t_flags flags);
int		preci_0_u(long nb, int len_nb, t_flags flags);
int		preci_0_width_0_u(long nb, int len_nb);
int		preci_0_width_1_u(long nb, int len_nb, t_flags flags);
int		preci_1_u(long nb, int len_nb, t_flags flags);
int		preci_1_width_0_u(long nb, int len_nb, t_flags flags);
int		preci_1_width_1_u(long nb, int len_nb, t_flags flags);
int		zero_case_u(t_flags flags);
void	no_minus_u(long nb, int real_width, int real_precision);
void	yes_minus_u(long nb, int real_width, int real_precision);

// %x
int		print_x(unsigned int n, t_flags flags);
int		preci_0_x(unsigned long nb, int len_nb, t_flags flags, int hashtag);
int		preci_0_w_0_x(unsigned long nb, int len_nb, t_flags flags, int hashtag);
int		preci_0_w_1_x(unsigned long nb, int len_nb, t_flags flags, int hashtag);
int		preci_1_x(unsigned long nb, int len_nb, t_flags flags, int hashtag);
int		preci_1_w_0_x(unsigned long nb, int len_nb, t_flags flags, int hashtag);
int		preci_1_w_1_x(unsigned long nb, int len_nb, t_flags f, int real_prec);

// %X
int		print_upx(unsigned int n, t_flags f);
int		preci_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag);
int		preci_0_w_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag);
int		preci_0_w_1_upx(unsigned long nb, int len_nb, t_flags f, int hashtag);
int		preci_1_upx(unsigned long nb, int len_nb, t_flags f, int hashtag);
int		preci_1_w_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag);
int		preci_1_w_1_upx(unsigned long nb, int len_nb, t_flags f, int real_prec);

// utils_1.c
int		width_or_precision(const char *s);
void	print_width_space(int nb);
void	print_zero(int nb);
int		pos_width(int width, int lenght);
int		count_flags(t_flags s);

// utils_2.c
int		int_len(long n);
int		int_len_zero(long n);
char	*ft_strndup(const char *s, size_t n);
void	ft_putnbr(long nb);
int		print_plus_or_space(long nb, t_flags flags);

// utils_3.c
int		print_hashtag_low(t_flags flags, unsigned long nb);
int		print_hashtag_up(t_flags flags, unsigned long nb);
int		determine_hashtag(t_flags flags, unsigned long nb);
int		intlen_hexa(unsigned long n);
int		intlen_hexa_zero(unsigned long n);

// utils_4.c
int		determine_plus_or_space(long nb, t_flags flags);
int		determine_plus(long nb, t_flags flags);
long	positive_nb(long nb);
void	putnbr_hexa(unsigned long nb, char c);
int		check_flags(char c);

// utils_5.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		print_real_width_1(int real_width);
int		print_real_width_2(int real_width, t_flags flags);
int		zero_case(t_flags flags);

// libft_functions.c
void	*my_calloc(size_t count, size_t size);
int		ft_strlen_pf(char *s);
void	ft_bzero_pf(void *s, size_t n);
int		ft_isdigit_pf(int c);

#endif