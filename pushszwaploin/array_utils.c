/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:37:15 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:37:42 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_dup(int *src, int size)
{
	int		index;
	int		*copy;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	index = 0;
	while (index < size)
	{
		copy[index] = src[index];
		index++;
	}
	return (copy);
}

void	array_sort(int *arr, int size)
{
	int		index;
	int		cursor;
	int		temp;

	index = 1;
	while (index < size)
	{
		temp = arr[index];
		cursor = index - 1;
		while (cursor >= 0 && arr[cursor] > temp)
		{
			arr[cursor + 1] = arr[cursor];
			cursor--;
		}
		arr[cursor + 1] = temp;
		index++;
	}
}

int	array_has_duplicates(int *arr, int size)
{
	int		index;

	index = 1;
	while (index < size)
	{
		if (arr[index] == arr[index - 1])
			return (1);
		index++;
	}
	return (0);
}

int	array_index_of(int *arr, int size, int value)
{
	int		low;
	int		high;
	int		mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == value)
			return (mid);
		if (arr[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}
