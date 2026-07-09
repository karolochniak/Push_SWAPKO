/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloin <tloin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:49:57 by tloin             #+#    #+#             */
/*   Updated: 2025/11/28 15:54:39 by tloin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}	t_stack;

typedef struct s_vec
{
	int			*data;
	int			size;
	int			capacity;
}	t_vec;

typedef struct s_state
{
	t_stack		a;
	t_stack		b;
	t_vec		values;
	int			*sorted;
}	t_state;

int		parse_arguments(int argc, char **argv, t_vec *values);
void	vec_init(t_vec *vec);
void	vec_free(t_vec *vec);
int		vec_push(t_vec *vec, int value);
int		*array_dup(int *src, int size);
void	array_sort(int *arr, int size);
int		array_has_duplicates(int *arr, int size);
int		array_index_of(int *arr, int size, int value);
void	stack_init(t_stack *stack);
void	stack_push_top(t_stack *stack, t_node *node);
void	stack_push_bottom(t_stack *stack, t_node *node);
t_node	*stack_pop_top(t_stack *stack);
t_node	*stack_pop_bottom(t_stack *stack);
void	stack_clear(t_stack *stack);
t_node	*node_new(int value, int index);
int		build_stack(t_stack *stack, t_vec *values, int *sorted);
int		stack_is_sorted(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *stack);
void	sort_small(t_stack *a, t_stack *b);
void	sort_radix(t_stack *a, t_stack *b);
void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);
int		is_space(char c);
int		is_digit(char c);
int		print_error(void);
void	cleanup_state(t_state *state);

#endif
