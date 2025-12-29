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

#include <stdbool.h>
#include <limits.h>
#include "printf/ft_printf.h"


typedef struct s_list
{
    int             value;     // Wartość liczbowa
    int             index;     // Zindeksowana wartość (ułatwia algorytmy typu Radix/K-sort)
    struct s_list   *next;     // Następny element
    struct s_list   *prev;     // Poprzedni element
} t_list;

// Funkcje operacji stosu
void    sa(t_list *a, int print);
void    sb(t_list *b, int print);
void    ss(t_list *a, t_list *b);
void    pa(t_list **a, t_list **b);
void    pb(t_list **a, t_list **b);
void    ra(t_list **a, int print);
void    rb(t_list **b, int print);
void    rr(t_list **a, t_list **b);
void    rra(t_list **a, int print);
void    rrb(t_list **b, int print);
void    rrr(t_list **a, t_list **b);

// Funkcje pomocznicze
long	ft_atoi_safe(const char *str, int *error);
/* adapted list helpers (ps_list.c) */
t_list  *ps_lstnew(int value);
void    ps_lstadd_back(t_list **lst, t_list *node);
t_list  *ps_lstlast(t_list *lst);
int     ps_lstsize(t_list *lst);
/* sort helpers */
void    sort_three(t_list **a);
/* compatibility wrappers for libft-style names used in rotation code */
t_list  *ft_lstlast(t_list *lst);
int	    check_dupli(t_list *a);
int	is_sorted(t_list *a);




#endif