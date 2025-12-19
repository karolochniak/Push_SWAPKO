/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotation1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:59:54 by kochniak          #+#    #+#             */
/*   Updated: 2025/12/19 14:04:06 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libftKO/libft.h"
#include "../printf/ft_printf.h"

void	sa(t_list *a, int print)
{
	int	tmp;
	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->next->value;
	a->next->value = a->value;
	a->value = tmp;
	if (print == 1) 
	ft_printf("sa\n");
}
void	sb(t_list *b, int print)
{
	int	tmp;
	if (b == NULL || b->next == NULL)
		return ;
	tmp = b->next->value;
	b->next->value = b->value;
	b->value = tmp;
	if (print == 1) 
	ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_list **b, t_list **a)
{
	t_list *node_to_move;
	
	if(!b || !*b)
		return ;
	node_to_move = *b;
	*b = (*b)->next;
	if(*b)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	node_to_move->prev = NULL;
	if(*a)
		(*a)->prev = node_to_move;
	*a = node_to_move;
	ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a)
{
	t_list *node_to_move;
	
	if(!a || !*a)
		return ;
	node_to_move = *a;
	*a = (*a)->next;
	if(*a)
		(*a)->prev = NULL;
	node_to_move->next = *b;
	node_to_move->prev = NULL;
	if(*b)
		(*b)->prev = node_to_move;
	*b = node_to_move;
	ft_printf("pb\n");
}

