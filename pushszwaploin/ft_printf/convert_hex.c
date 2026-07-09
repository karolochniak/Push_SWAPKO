/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:06:17 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 16:11:40 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hx_prefix(t_fmt *fm, t_hexcalc *x, int up, unsigned long n);
static int	h_write_dig(t_fmt *fm, t_hexcalc *x, unsigned long n, int up);

int	cv_hex(t_fmt *fm, unsigned long n, int up)
{
	t_hexcalc	x;
	int			r;
	int			d;

	hex_compute(fm, n, 16, &x);
	r = 0;
	d = hx_prefix(fm, &x, up, n);
	if (d < 0)
		return (0);
	r += d;
	d = h_write_dig(fm, &x, n, up);
	if (d < 0)
		return (0);
	r += d;
	if (fm->m)
		r += putnchar(' ', maxi(0, x.pad));
	fm->c = r;
	return (1);
}

static int	hx_prefix(t_fmt *fm, t_hexcalc *x, int up, unsigned long n)
{
	int	added;

	added = 0;
	if (!fm->m)
	{
		if (fm->z && !fm->ps)
		{
			if (!hex_write_prefix(fm, up, n))
				return (-1);
			added += x->prelen;
			added += putnchar('0', maxi(0, x->pad));
		}
		else
			added += putnchar(' ', maxi(0, x->pad));
	}
	if (!(fm->z && !fm->ps))
	{
		if (!hex_write_prefix(fm, up, n))
			return (-1);
		added += x->prelen;
	}
	return (added);
}

static int	h_write_dig(t_fmt *fm, t_hexcalc *x, unsigned long n, int up)
{
	char	buf[32];
	int		added;

	added = 0;
	added += putnchar('0', x->zc);
	if (x->nd)
	{
		if (!u_to_str_base(n, buf, 16, up))
			return (-1);
		if (write(1, buf, x->nd) != x->nd)
			return (-1);
		added += x->nd;
	}
	else if (!(fm->ps && fm->p == 0 && n == 0))
		added += x->nd;
	return (added);
}
