/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:02:57 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 14:04:34 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad_left(t_fmt *fm, int neg, int len, int zcount)
{
	int	k;
	int	r;
	int	sign;

	sign = (neg || fm->pl || fm->sp);
	k = fm->w - (len + zcount + sign);
	r = 0;
	if (!fm->m)
	{
		if (fm->z && !fm->ps)
			r += putnchar('0', maxi(0, k));
		else
			r += putnchar(' ', maxi(0, k));
	}
	return (r);
}

int	pad_right(t_fmt *fm, int len)
{
	return (putnchar(' ', maxi(0, fm->w - len)));
}
