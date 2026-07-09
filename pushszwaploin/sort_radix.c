/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:40:48 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	t_node	*node;
	int		max;
	int		bits;

	node = a->top;
	max = 0;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	if (bits == 0)
		bits = 1;
	return (bits);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int		size;
	int		bits;
	int		bit;
	int		count;

	size = a->size;
	bits = max_bits(a);
	bit = 0;
	while (bit < bits)
	{
		count = 0;
		while (count < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				op_pb(a, b);
			else
				op_ra(a);
			count++;
		}
		while (b->size > 0)
			op_pa(a, b);
		bit++;
	}
}
