/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:31:33 by kochniak          #+#    #+#             */
/*   Updated: 2026/03/03 00:00:00 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	read_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoi_safe(const char *str, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = skip_spaces(str);
	sign = read_sign(str, &i);
	if (!is_digit(str[i]))
		return (*error = 1, 0);
	while (is_digit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
			return (*error = 1, 0);
		i++;
	}
	if (str[i] != '\0')
		return (*error = 1, 0);
	return (res * sign);
}
