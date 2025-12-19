/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotation2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:59:54 by kochniak          #+#    #+#             */
/*   Updated: 2025/12/19 14:21:20 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libftKO/libft.h"
#include "../printf/ft_printf.h"

void	ra(t_list **a, int print)
{
	t_list *first;
	t_list *last;
	
	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if(print == 1)
		ft_printf("ra\n");
}

void	rb(t_list **b, int print)
{
	t_list *first;
	t_list *last;
	
	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if(print == 1)
		ft_printf("rb\n");
}

void	rra(t_list **a, int print)
{
	t_list *last;
	
	if (!a || !*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	last->prev->next= NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	*a = last;
	if(print == 1)
		ft_printf("rra\n");
}
void	rrb(t_list **b, int print)
{
	t_list *last;
	
	if (!b || !*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	last->prev->next= NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	*b = last;
	if(print == 1)
		ft_printf("rra\n");
}
void    rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}


