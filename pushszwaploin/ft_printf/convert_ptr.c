/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:52:34 by tloin             #+#    #+#             */
/*   Updated: 2025/10/20 13:48:48 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_prefix(t_fmt *fm, t_hexcalc *x);
static int	ptr_write_digits(t_hexcalc *x, unsigned long n);
static int	handle_null_ptr(t_fmt *fm);

int	cv_ptr(t_fmt *fm, unsigned long n)
{
	t_hexcalc	x;
	int			r;
	int			d;

	if (n == 0)
		return (handle_null_ptr(fm));
	hex_compute(fm, n, 16, &x);
	x.prelen = 2;
	x.pad = maxi(0, fm->w - (x.nd + x.zc + x.prelen));
	r = 0;
	d = ptr_prefix(fm, &x);
	if (d < 0)
		return (0);
	r += d;
	d = ptr_write_digits(&x, n);
	if (d < 0)
		return (0);
	r += d;
	if (fm->m)
		r += putnchar(' ', maxi(0, x.pad));
	fm->c = r;
	return (1);
}

static int	ptr_prefix(t_fmt *fm, t_hexcalc *x)
{
	int	added;

	added = 0;
	if (!fm->m)
	{
		if (fm->z && !fm->ps)
		{
			if (write(1, "0x", 2) != 2)
				return (-1);
			added += 2;
			added += putnchar('0', maxi(0, x->pad));
		}
		else
			added += putnchar(' ', maxi(0, x->pad));
	}
	if (!(fm->z && !fm->ps))
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		added += 2;
	}
	return (added);
}

static int	handle_null_ptr(t_fmt *fm)
{
	int	r;

	r = 0;
	if (!fm->m)
		r += putnchar(' ', maxi(0, fm->w - 5));
	r += putstrn("(nil)", 5);
	if (fm->m)
		r += putnchar(' ', maxi(0, fm->w - 5));
	fm->c = r;
	return (1);
}

static int	ptr_write_digits(t_hexcalc *x, unsigned long n)
{
	char	buf[32];
	int		added;

	added = 0;
	added += putnchar('0', x->zc);
	if (x->nd)
	{
		if (!u_to_str_base(n, buf, 16, 0))
			return (-1);
		if (write(1, buf, x->nd) != x->nd)
			return (-1);
		added += x->nd;
	}
	return (added);
}
