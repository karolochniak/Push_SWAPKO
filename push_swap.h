/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:31:18 by kochniak          #+#    #+#             */
/*   Updated: 2025/12/12 20:45:38 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "printf/ft_printf.h"
#include "libftKO/libft.h"

typedef struct s_stack_node
{
	int     nbr;
    int     index;
    int     push_cost;
    bool    above_median;
    bool    cheapest;
    struct S_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;

//Handle errors

//Stack initiation

//Nodes initiation

//Commands

//Algorithms



#endif