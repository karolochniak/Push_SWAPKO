/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char_str_percent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:48:31 by tloin             #+#    #+#             */
/*   Updated: 2025/10/20 13:44:28 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*resolve_null_str(t_fmt *fm, const char *s, int *len);

int	cv_char(t_fmt *fm, int ch)
{
	int	r;
	int	pad;

	r = 0;
	pad = maxi(0, fm->w - 1);
	if (!fm->m)
		r += putnchar(' ', pad);
	if (write(1, &ch, 1) != 1)
		return (0);
	r++;
	if (fm->m)
		r += putnchar(' ', pad);
	fm->c = r;
	return (1);
}

int	cv_str(t_fmt *fm, const char *s)
{
	int	r;
	int	len;

	r = 0;
	s = resolve_null_str(fm, s, &len);
	if (s)
		len = (int)ft_strlen(s);
	if (fm->ps)
		len = mini(len, fm->p);
	if (!fm->m)
		r += putnchar(' ', maxi(0, fm->w - len));
	r += putstrn(s, len);
	if (fm->m)
		r += putnchar(' ', maxi(0, fm->w - len));
	fm->c = r;
	return (1);
}

static const char	*resolve_null_str(t_fmt *fm, const char *s, int *len)
{
	if (s)
		return (s);
	if (fm->ps)
	{
		*len = 0;
		if (fm->p < 6)
			return (NULL);
		return ("(null)");
	}
	return ("(null)");
}

int	cv_pct(t_fmt *fm)
{
	int	r;
	int	pad;
	int	ch;

	r = 0;
	ch = '%';
	pad = maxi(0, fm->w - 1);
	if (!fm->m)
	{
		if (fm->z)
			r += putnchar('0', pad);
		else
			r += putnchar(' ', pad);
	}
	if (write(1, &ch, 1) != 1)
		return (0);
	r++;
	if (fm->m)
		r += putnchar(' ', pad);
	fm->c = r;
	return (1);
}
