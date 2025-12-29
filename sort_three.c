/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@local>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2025/12/29 00:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_list **a)
{
    int a0, a1, a2;

    if (!a || !*a)
        return ;
    if (ps_lstsize(*a) == 2)
    {
        if ((*a)->value > (*a)->next->value)
            sa(*a, 1);
        return ;
    }
    a0 = (*a)->value;
    a1 = (*a)->next->value;
    a2 = (*a)->next->next->value;
    if (a0 > a1 && a1 < a2 && a0 < a2)
        sa(*a, 1);
    else if (a0 > a1 && a1 > a2 && a0 > a2)
    {
        sa(*a, 1);
        rra(a, 1);
    }
    else if (a0 > a1 && a1 < a2 && a0 > a2)
        ra(a, 1);
    else if (a0 < a1 && a1 > a2 && a0 < a2)
    {
        sa(*a, 1);
        ra(a, 1);
    }
    else if (a0 < a1 && a1 > a2 && a0 > a2)
        rra(a, 1);
}
