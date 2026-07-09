/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:00:00 by tloin             #+#    #+#             */
/*   Updated: 2025/10/17 14:50:28 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_num(const char **s, int *dst)
{
	long	v;

	v = 0;
	while (ft_isdigit(**s))
	{
		v = v * 10 + (**s - '0');
		(*s)++;
	}
	if (v > 2147483647)
		v = 2147483647;
	*dst = (int)v;
}

void	parse_flags(const char **f, t_fmt *fm)
{
	while (**f == '-' || **f == '0' || **f == '+' || **f == ' ' || **f == '#')
	{
		if (**f == '-')
			fm->m = 1;
		else if (**f == '0')
			fm->z = 1;
		else if (**f == '+')
			fm->pl = 1;
		else if (**f == ' ')
			fm->sp = 1;
		else if (**f == '#')
			fm->h = 1;
		(*f)++;
	}
}

void	parse_width(const char **f, va_list *ap, t_fmt *fm)
{
	if (**f == '*')
	{
		fm->w = va_arg(*ap, int);
		if (fm->w < 0)
		{
			fm->m = 1;
			fm->w = -fm->w;
		}
		(*f)++;
		return ;
	}
	read_num(f, &fm->w);
}

void	parse_precision(const char **f, va_list *ap, t_fmt *fm)
{
	if (**f != '.')
		return ;
	fm->ps = 1;
	(*f)++;
	if (**f == '*')
	{
		fm->p = va_arg(*ap, int);
		if (fm->p < 0)
		{
			fm->ps = 0;
			fm->p = 0;
		}
		(*f)++;
		return ;
	}
	read_num(f, &fm->p);
}

int	parse_specifier(const char **f, t_fmt *fm)
{
	if (**f == 'c' || **f == 's' || **f == 'p' || **f == 'd' || **f == 'i')
	{
		fm->s = *(*f)++;
		return (1);
	}
	if (**f == 'u' || **f == 'x' || **f == 'X' || **f == '%')
	{
		fm->s = *(*f)++;
		return (1);
	}
	return (0);
}
