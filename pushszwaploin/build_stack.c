/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:38:25 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:45:14 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_stack(t_stack *stack, t_vec *values, int *sorted)
{
	int		index;
	int		position;
	t_node	*node;

	index = 0;
	while (index < values->size)
	{
		position = array_index_of(sorted, values->size, values->data[index]);
		if (position < 0)
			return (0);
		node = node_new(values->data[index], position);
		if (!node)
			return (0);
		stack_push_bottom(stack, node);
		index++;
	}
	return (1);
}
