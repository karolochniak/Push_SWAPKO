/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 00:00:00 by kochniak          #+#    #+#             */
/*   Updated: 2026/03/03 00:00:00 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	choose_sort(t_list **a, t_list **b)
{
	int	size;

	size = ps_lstsize(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
		radix_sort(a, b);
}

static int	print_error_and_free(t_list **a, t_list **b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_args_to_stack(argc, argv, &a) != 0)
		return (print_error_and_free(&a, &b));
	if (check_dupli(a) != 0)
		return (print_error_and_free(&a, &b));
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	assign_indexes(a);
	choose_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
