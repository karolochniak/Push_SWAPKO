/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:30:00 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 15:50:00 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(t_fmt *fm, int neg)
{
	if (neg)
	{
		if (write(1, "-", 1) != 1)
			return (0);
		return (1);
	}
	if (fm->pl)
	{
		if (write(1, "+", 1) != 1)
			return (0);
		return (1);
	}
	if (fm->sp)
	{
		if (write(1, " ", 1) != 1)
			return (0);
		return (1);
	}
	return (1);
}

void	int_compute(t_fmt *fm, long n, char *buf, t_intcalc *x)
{
	unsigned long	u;

	if (n < 0)
	{
		u = (unsigned long)(-n);
		x->neg = 1;
	}
	else
	{
		u = (unsigned long)n;
		x->neg = 0;
	}
	x->nd = u_to_str_base(u, buf, 10, 0);
	if (fm->ps && fm->p == 0 && n == 0)
		x->nd = 0;
	x->zc = x->nd;
	if (fm->ps)
		x->zc = maxi(0, fm->p - x->nd);
	else
		x->zc = 0;
	x->pad = fm->w - (x->nd + x->zc + (x->neg || fm->pl || fm->sp));
}
