/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:52:13 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 16:23:12 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prepad_and_sign(t_fmt *fm, t_intcalc *x, int *r);
static int	print_sign_if_needed(t_fmt *fm, t_intcalc *x, int *r);
static int	write_digits_and_zeros(char *buf, t_intcalc *x, int *r);

int	cv_int(t_fmt *fm, long n)
{
	char		buf[32];
	t_intcalc	x;
	int			r;

	int_compute(fm, n, buf, &x);
	r = 0;
	if (!prepad_and_sign(fm, &x, &r))
		return (0);
	if (!print_sign_if_needed(fm, &x, &r))
		return (0);
	if (!write_digits_and_zeros(buf, &x, &r))
		return (0);
	if (fm->m)
		r += putnchar(' ', maxi(0, x.pad));
	fm->c = r;
	return (1);
}

static int	prepad_and_sign(t_fmt *fm, t_intcalc *x, int *r)
{
	if (!fm->m)
	{
		if (fm->z && !fm->ps)
		{
			if (x->neg || fm->pl || fm->sp)
			{
				if (!print_sign(fm, x->neg))
					return (0);
				(*r)++;
			}
			*r += putnchar('0', maxi(0, x->pad));
		}
		else
			*r += putnchar(' ', maxi(0, x->pad));
	}
	return (1);
}

static int	print_sign_if_needed(t_fmt *fm, t_intcalc *x, int *r)
{
	if (!(fm->z && !fm->ps))
	{
		if (!print_sign(fm, x->neg))
			return (0);
		if (x->neg || fm->pl || fm->sp)
			(*r)++;
	}
	return (1);
}

static int	write_digits_and_zeros(char *buf, t_intcalc *x, int *r)
{
	*r += putnchar('0', x->zc);
	if (x->nd && write(1, buf, x->nd) != x->nd)
		return (0);
	*r += x->nd;
	return (1);
}
