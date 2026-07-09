/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:39:03 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 15:29:26 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_fmt
{
	int		m;
	int		z;
	int		pl;
	int		sp;
	int		h;
	int		w;
	int		p;
	int		ps;
	char	s;
	int		c;
}	t_fmt;

typedef struct s_intcalc
{
	int	neg;
	int	nd;
	int	zc;
	int	pad;
}	t_intcalc;

typedef struct s_hexcalc
{
	int	nd;
	int	zc;
	int	pad;
	int	prelen;
}	t_hexcalc;

int		ft_printf(const char *fmt, ...);
int		parse(const char **f, va_list *ap, t_fmt *fm);
int		handle_conv(t_fmt *fm, va_list *ap);
void	parse_flags(const char **f, t_fmt *fm);
void	read_num(const char **s, int *dst);
int		parse_specifier(const char **f, t_fmt *fm);
void	parse_width(const char **f, va_list *ap, t_fmt *fm);
void	parse_precision(const char **f, va_list *ap, t_fmt *fm);

int		cv_char(t_fmt *fm, int ch);
int		cv_str(t_fmt *fm, const char *s);
int		cv_pct(t_fmt *fm);
int		cv_int(t_fmt *fm, long n);
int		cv_uint(t_fmt *fm, unsigned long n);
int		cv_hex(t_fmt *fm, unsigned long n, int up);
int		cv_ptr(t_fmt *fm, unsigned long n);

int		pad_left(t_fmt *fm, int neg, int len, int zcount);
int		pad_right(t_fmt *fm, int len);

int		putnchar(int ch, int n);
int		putstrn(const char *s, int n);
size_t	ft_strlen(const char *s);

int		u_to_str_base(unsigned long n, char *buf, int base, int up);
int		i_to_str_abs(long n, char *buf);
int		numlen_base(unsigned long n, int base);
int		maxi(int a, int b);
int		mini(int a, int b);

int		print_sign(t_fmt *fm, int neg);
void	int_compute(t_fmt *fm, long n, char *buf, t_intcalc *x);

int		hex_prefix_len(t_fmt *fm, unsigned long n);
int		hex_write_prefix(t_fmt *fm, int up, unsigned long n);
void	hex_compute(t_fmt *fm, unsigned long n, int base, t_hexcalc *x);
#endif