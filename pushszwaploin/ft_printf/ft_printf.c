/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:50:59 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 16:23:00 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	init_fmt(t_fmt *fm)
{
	fm->m = 0;
	fm->z = 0;
	fm->pl = 0;
	fm->sp = 0;
	fm->h = 0;
	fm->w = 0;
	fm->p = 0;
	fm->ps = 0;
	fm->s = 0;
	fm->c = 0;
}

static int	process_percent(const char **fmt, va_list *aq, int *acc)
{
	t_fmt	fm;

	init_fmt(&fm);
	if (!parse(fmt, aq, &fm))
		return (-1);
	if (!handle_conv(&fm, aq))
		return (-1);
	*acc += fm.c;
	return (1);
}

static int	process_literal(const char **fmt, int *acc)
{
	if (write(1, *fmt, 1) != 1)
		return (-1);
	(*acc)++;
	(*fmt)++;
	return (1);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	va_list	aq;
	int		r;

	(void)fd;
	r = 0;
	va_copy(aq, ap);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (process_percent(&fmt, &aq, &r) < 0)
			{
				va_end(aq);
				return (-1);
			}
		}
		else if (process_literal(&fmt, &r) < 0)
		{
			va_end(aq);
			return (-1);
		}
	}
	va_end(aq);
	return (r);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, fmt);
	r = ft_vdprintf(1, fmt, ap);
	va_end(ap);
	return (r);
}
