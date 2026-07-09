/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:36:56 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:37:33 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vec_init(t_vec *vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = 0;
}

void	vec_free(t_vec *vec)
{
	free(vec->data);
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = 0;
}

int	vec_push(t_vec *vec, int value)
{
	int		new_capacity;
	int		index;
	int		*new_data;

	if (vec->size == vec->capacity)
	{
		new_capacity = 4;
		if (vec->capacity > 0)
			new_capacity = vec->capacity * 2;
		new_data = malloc(sizeof(int) * new_capacity);
		if (!new_data)
			return (0);
		index = 0;
		while (index < vec->size)
		{
			new_data[index] = vec->data[index];
			index++;
		}
		free(vec->data);
		vec->data = new_data;
		vec->capacity = new_capacity;
	}
	vec->data[vec->size] = value;
	vec->size++;
	return (1);
}
