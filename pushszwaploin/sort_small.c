/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:40:30 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lowest_pos(t_stack *stack)
{
	t_node	*node;
	int		pos;
	int		best_pos;
	int		best_index;

	node = stack->top;
	best_pos = 0;
	best_index = node->index;
	pos = 0;
	while (node)
	{
		if (node->index < best_index)
		{
			best_index = node->index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (best_pos);
}

static void	push_lowest(t_stack *a, t_stack *b)
{
	int		pos;
	int		size;
	int		moves;

	pos = find_lowest_pos(a);
	size = a->size;
	if (pos <= size / 2)
	{
		moves = pos;
		while (moves > 0)
		{
			op_ra(a);
			moves--;
		}
	}
	else
	{
		moves = size - pos;
		while (moves > 0)
		{
			op_rra(a);
			moves--;
		}
	}
	op_pb(a, b);
}

static void	sort_four(t_stack *a, t_stack *b)
{
	push_lowest(a, b);
	sort_three(a);
	op_pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	push_lowest(a, b);
	push_lowest(a, b);
	sort_three(a);
	op_pa(a, b);
	op_pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}
