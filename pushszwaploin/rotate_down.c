/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:39:37 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 16:49:30 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_down(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (0);
	node = stack_pop_bottom(stack);
	if (!node)
		return (0);
	stack_push_top(stack, node);
	return (1);
}

void	op_rra(t_stack *a)
{
	if (rotate_down(a))
		ft_printf("rra\n");
}

void	op_rrb(t_stack *b)
{
	if (rotate_down(b))
		ft_printf("rrb\n");
}

void	op_rrr(t_stack *a, t_stack *b)
{
	int		changed;

	changed = 0;
	if (rotate_down(a))
		changed = 1;
	if (rotate_down(b))
		changed = 1;
	if (changed)
		ft_printf("rrr\n");
}
