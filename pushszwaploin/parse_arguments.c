/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:36:20 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:36:20 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_number(char *str, int *pos, int *number)
{
	long	value;
	int		sign;
	int		found;

	value = 0;
	sign = 1;
	found = 0;
	if (str[*pos] == '+' || str[*pos] == '-')
	{
		if (str[*pos] == '-')
			sign = -1;
		(*pos)++;
	}
	while (is_digit(str[*pos]))
	{
		value = value * 10 + (str[*pos] - '0');
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && -(value) < INT_MIN))
			return (0);
		(*pos)++;
		found = 1;
	}
	if ((str[*pos] && !is_space(str[*pos])) || !found)
		return (0);
	return (*number = (int)(value * sign), 1);
}

static int	parse_argument(char *arg, t_vec *values, int *parsed)
{
	int		index;
	int		number;

	index = 0;
	while (arg[index])
	{
		while (arg[index] && is_space(arg[index]))
			index++;
		if (!arg[index])
			break ;
		if (!read_number(arg, &index, &number))
			return (0);
		if (!vec_push(values, number))
			return (0);
		*parsed = 1;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_vec *values)
{
	int		index;
	int		parsed;

	index = 1;
	parsed = 0;
	while (index < argc)
	{
		if (!parse_argument(argv[index], values, &parsed))
			return (0);
		index++;
	}
	return (parsed);
}
