/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2025/12/29 00:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list  *ps_lstnew(int value)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = 0;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

t_list  *ps_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void    ps_lstadd_back(t_list **lst, t_list *node)
{
    t_list *last;

    if (!lst || !node)
        return ;
    if (!*lst)
    {
        *lst = node;
        return ;
    }
    last = ps_lstlast(*lst);
    last->next = node;
    node->prev = last;
}

int ps_lstsize(t_list *lst)
{
    int n = 0;
    while (lst)
    {
        n++;
        lst = lst->next;
    }
    return (n);
}
int is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

