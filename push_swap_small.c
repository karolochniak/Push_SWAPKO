/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:00:00 by copilot            #+#    #+#             */
/*   Updated: 2026/07/13 00:00:00 by copilot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lowest_pos(t_list *stack)
{
	t_list	*node;
	int		pos;
	int		best_pos;
	int		best_index;

	if (!stack)
		return (0);
	node = stack;
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

static void	push_lowest(t_list **a, t_list **b)
{
	int	pos;
	int	size;
	int	moves;

	if (!a || !*a || !b)
		return ;
	pos = find_lowest_pos(*a);
	size = ps_lstsize(*a);
	if (pos <= size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			ra(a, 1);
	}
	else
	{
		moves = size - pos;
		while (moves-- > 0)
			rra(a, 1);
	}
	pb(b, a);
}

static void	sort_four(t_list **a, t_list **b)
{
	push_lowest(a, b);
	sort_three(a);
	pa(b, a);
}

static void	sort_five(t_list **a, t_list **b)
{
	push_lowest(a, b);
	push_lowest(a, b);
	sort_three(a);
	pa(b, a);
	pa(b, a);
}

void	sort_small(t_list **a, t_list **b)
{
	if (!a || !*a || !b)
		return ;
	if (ps_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ps_lstsize(*a) == 5)
		sort_five(a, b);
}