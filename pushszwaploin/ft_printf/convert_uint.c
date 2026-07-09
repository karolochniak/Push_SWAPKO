/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:57:36 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 15:05:08 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cv_uint_prepad(t_fmt *fm, int pad, int *r);
static int	cv_uint_write(char *buf, int nd, int zc, int *r);

int	cv_uint(t_fmt *fm, unsigned long n)
{
	char	buf[32];
	int		nd;
	int		zc;
	int		pad;
	int		r;

	nd = u_to_str_base(n, buf, 10, 0);
	if (fm->ps && fm->p == 0 && n == 0)
		nd = 0;
	if (fm->ps)
		zc = maxi(0, fm->p - nd);
	else
		zc = 0;
	pad = fm->w - (nd + zc);
	r = 0;
	if (!cv_uint_prepad(fm, pad, &r))
		return (0);
	if (!cv_uint_write(buf, nd, zc, &r))
		return (0);
	if (fm->m)
		r += putnchar(' ', maxi(0, pad));
	fm->c = r;
	return (1);
}

static int	cv_uint_prepad(t_fmt *fm, int pad, int *r)
{
	if (!fm->m)
	{
		if (fm->z && !fm->ps)
			*r += putnchar('0', maxi(0, pad));
		else
			*r += putnchar(' ', maxi(0, pad));
	}
	return (1);
}

static int	cv_uint_write(char *buf, int nd, int zc, int *r)
{
	*r += putnchar('0', zc);
	if (nd && write(1, buf, nd) != nd)
		return (0);
	*r += nd;
	return (1);
}
