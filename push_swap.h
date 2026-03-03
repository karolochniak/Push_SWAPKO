/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:31:18 by kochniak          #+#    #+#             */
/*   Updated: 2025/12/19 14:32:45 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	sa(t_list *a, int print);
void	sb(t_list *b, int print);
void	ss(t_list *a, t_list *b);
void	pa(t_list **b, t_list **a);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a, int print);
void	rb(t_list **b, int print);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int print);
void	rrb(t_list **b, int print);
void	rrr(t_list **a, t_list **b);

long	ft_atoi_safe(const char *str, int *error);
t_list	*ps_lstnew(int value);
void	ps_lstadd_back(t_list **lst, t_list *node);
t_list	*ps_lstlast(t_list *lst);
int		ps_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		is_sorted(t_list *a);

int		check_dupli(t_list *a);
void	free_stack(t_list **stack);

int		parse_args_to_stack(int argc, char **argv, t_list **a);

int		assign_indexes(t_list *a);
int		get_max_index(t_list *a);

void	sort_two(t_list **a);
void	sort_three(t_list **a);

void	radix_sort(t_list **a, t_list **b);

#endif