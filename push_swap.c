/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:46:22 by kochniak          #+#    #+#             */
/*   Updated: 2025/12/19 14:33:24 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	t_list  *a;
	char    *sdup;
	char    *tok;
	long    val;
	int     err;
	int     i;

	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		sdup = strdup(argv[1]);
		if (!sdup)
			return (1);
		tok = strtok(sdup, " \t\n\v\f\r");
		while (tok)
		{
			err = 0;
			val = ft_atoi_safe(tok, &err);
			if (err)
			{
				ft_printf("Error\n");
				free(sdup);
				return (1);
			}
			ps_lstadd_back(&a, ps_lstnew((int)val));
			tok = strtok(NULL, " \t\n\v\f\r");
		}
		free(sdup);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			err = 0;
			val = ft_atoi_safe(argv[i], &err);
			if (err)
			{
				ft_printf("Error\n");
				return (1);
			}
			ps_lstadd_back(&a, ps_lstnew((int)val));
			i++;
		}
	}
	if (check_dupli(a))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (is_sorted(a))
		return (0);
	/* TODO: call sorting algorithm here */
	return (0);
}