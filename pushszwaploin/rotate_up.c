/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:39:19 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_up(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (0);
	node = stack_pop_top(stack);
	if (!node)
		return (0);
	stack_push_bottom(stack, node);
	return (1);
}

void	op_ra(t_stack *a)
{
	if (rotate_up(a))
		ft_printf("ra\n");
}

void	op_rb(t_stack *b)
{
	if (rotate_up(b))
		ft_printf("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	int		changed;

	changed = 0;
	if (rotate_up(a))
		changed = 1;
	if (rotate_up(b))
		changed = 1;
	if (changed)
		ft_printf("rr\n");
}
