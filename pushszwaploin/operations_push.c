/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:39:01 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop_top(b);
	if (!node)
		return ;
	stack_push_top(a, node);
	ft_printf("pa\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop_top(a);
	if (!node)
		return ;
	stack_push_top(b, node);
	ft_printf("pb\n");
}
