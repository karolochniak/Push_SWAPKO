/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:00:51 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 16:11:40 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_prefix_len(t_fmt *fm, unsigned long n)
{
	if (fm->h && n != 0)
		return (2);
	return (0);
}

int	hex_write_prefix(t_fmt *fm, int up, unsigned long n)
{
	if (!(fm->h && n != 0))
		return (1);
	if (!up)
		return (write(1, "0x", 2) == 2);
	return (write(1, "0X", 2) == 2);
}

void	hex_compute(t_fmt *fm, unsigned long n, int base, t_hexcalc *x)
{
	int	zc;

	x->nd = numlen_base(n, base);
	if (fm->ps && fm->p == 0 && n == 0)
		x->nd = 0;
	x->prelen = hex_prefix_len(fm, n);
	zc = 0;
	if (fm->ps)
		zc = maxi(0, fm->p - x->nd);
	x->zc = zc;
	x->pad = maxi(0, fm->w - (x->nd + x->zc + x->prelen));
}
