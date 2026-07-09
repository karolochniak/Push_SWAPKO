/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:07:01 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 15:23:00 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_to_str_base(unsigned long n, char *buf, int base, int up)
{
	char		*d1;
	char		*d2;
	int			i;
	int			j;
	char		tmp[32];

	i = 0;
	d1 = "0123456789abcdef";
	d2 = "0123456789ABCDEF";
	if (n == 0)
		tmp[i++] = '0';
	while (n)
	{
		if (up)
			tmp[i++] = d2[n % (unsigned)base];
		else
			tmp[i++] = d1[n % (unsigned)base];
		n /= (unsigned)base;
	}
	j = 0;
	while (i--)
		buf[j++] = tmp[i];
	return (j);
}

int	i_to_str_abs(long n, char *buf)
{
	unsigned long	u;

	if (n < 0)
		u = (unsigned long)(-n);
	else
		u = (unsigned long)n;
	return (u_to_str_base(u, buf, 10, 0));
}
