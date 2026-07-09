/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:38:50 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 15:04:41 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse(const char **f, va_list *ap, t_fmt *fm)
{
	parse_flags(f, fm);
	parse_width(f, ap, fm);
	parse_precision(f, ap, fm);
	if (!parse_specifier(f, fm))
		return (0);
	if (fm->m)
		fm->z = 0;
	return (1);
}

int	handle_conv(t_fmt *fm, va_list *ap)
{
	if (fm->s == 'c')
		return (cv_char(fm, va_arg(*ap, int)));
	if (fm->s == 's')
		return (cv_str(fm, va_arg(*ap, const char *)));
	if (fm->s == '%')
		return (cv_pct(fm));
	if (fm->s == 'd' || fm->s == 'i')
		return (cv_int(fm, (long)va_arg(*ap, int)));
	if (fm->s == 'u')
		return (cv_uint(fm, (unsigned long)va_arg(*ap, unsigned int)));
	if (fm->s == 'x')
		return (cv_hex(fm, (unsigned long)va_arg(*ap, unsigned int), 0));
	if (fm->s == 'X')
		return (cv_hex(fm, (unsigned long)va_arg(*ap, unsigned int), 1));
	if (fm->s == 'p')
		return (cv_ptr(fm, (unsigned long)va_arg(*ap, void *)));
	return (0);
}
