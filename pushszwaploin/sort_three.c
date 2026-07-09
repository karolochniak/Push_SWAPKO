/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:40:12 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || stack->size != 3)
		return ;
	a = stack->top->index;
	b = stack->top->next->index;
	c = stack->bottom->index;
	if (a > b && b < c && a < c)
		op_sa(stack);
	else if (a > b && b > c)
	{
		op_sa(stack);
		op_rra(stack);
	}
	else if (a > b && b < c && a > c)
		op_ra(stack);
	else if (a < b && b > c && a < c)
	{
		op_sa(stack);
		op_ra(stack);
	}
	else if (a < b && b > c && a > c)
		op_rra(stack);
}
