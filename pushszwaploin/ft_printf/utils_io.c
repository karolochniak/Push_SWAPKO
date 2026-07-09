/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:21 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 14:55:46 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnchar(int ch, int n)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (i < n)
	{
		if (write(1, &ch, 1) != 1)
			return (r);
		r++;
		i++;
	}
	return (r);
}

int	putstrn(const char *s, int n)
{
	int	r;
	int	i;

	if (!s)
		return (0);
	r = 0;
	i = 0;
	while (i < n)
	{
		if (write(1, s + i, 1) != 1)
			return (r);
		r++;
		i++;
	}
	return (r);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
