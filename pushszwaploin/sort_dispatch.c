/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:41:07 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			op_sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	if (a->size <= 5)
	{
		sort_small(a, b);
		return ;
	}
	sort_radix(a, b);
}
