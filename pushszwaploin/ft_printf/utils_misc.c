/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:08:43 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 14:52:22 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen_base(unsigned long n, int base)
{
	int	l;

	l = 1;
	while (n >= (unsigned long)base)
	{
		n /= (unsigned long)base;
		l++;
	}
	return (l);
}

int	maxi(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	mini(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
