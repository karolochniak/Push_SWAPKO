/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:37:34 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:13 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	stack_push_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->prev = NULL;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	else
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

void	stack_push_bottom(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = NULL;
	node->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = node;
	else
		stack->top = node;
	stack->bottom = node;
	stack->size++;
}
