/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:38:44 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	return (1);
}

void	op_sa(t_stack *a)
{
	if (swap_top(a))
		ft_printf("sa\n");
}

void	op_sb(t_stack *b)
{
	if (swap_top(b))
		ft_printf("sb\n");
}

void	op_ss(t_stack *a, t_stack *b)
{
	int		changed;

	changed = 0;
	if (swap_top(a))
		changed = 1;
	if (swap_top(b))
		changed = 1;
	if (changed)
		ft_printf("ss\n");
}
