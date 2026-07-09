/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:56:34 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 14:56:29 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	load_data(t_state *state, int argc, char **argv)
{
	if (!parse_arguments(argc, argv, &state->values))
		return (-1);
	if (state->values.size == 0)
		return (0);
	state->sorted = array_dup(state->values.data, state->values.size);
	if (!state->sorted)
		return (-1);
	array_sort(state->sorted, state->values.size);
	if (array_has_duplicates(state->sorted, state->values.size))
		return (-1);
	if (!build_stack(&state->a, &state->values, state->sorted))
		return (-1);
	return (1);
}

static int	handle_failure(t_state *state)
{
	cleanup_state(state);
	return (print_error());
}

static int	run_push_swap(int argc, char **argv)
{
	int		status;
	t_state	state;

	vec_init(&state.values);
	stack_init(&state.a);
	stack_init(&state.b);
	state.sorted = NULL;
	status = load_data(&state, argc, argv);
	if (status == -1)
		return (handle_failure(&state));
	if (status == 0)
	{
		cleanup_state(&state);
		return (1);
	}
	sort_stack(&state.a, &state.b);
	cleanup_state(&state);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!run_push_swap(argc, argv))
		return (1);
	return (0);
}
