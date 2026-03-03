#include "push_swap.h"

int	assign_indexes(t_list *a)
{
	t_list	*curr;
	t_list	*scan;
	int		index;

	curr = a;
	while (curr)
	{
		index = 0;
		scan = a;
		while (scan)
		{
			if (scan->value < curr->value)
				index++;
			scan = scan->next;
		}
		curr->index = index;
		curr = curr->next;
	}
	return (0);
}

int	get_max_index(t_list *a)
{
	int	max;

	if (!a)
		return (0);
	max = a->index;
	a = a->next;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

void	sort_two(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(*a, 1);
}

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(*a, 1);
	else if (x > y && y > z)
	{
		sa(*a, 1);
		rra(a, 1);
	}
	else if (x > y && y < z && x > z)
		ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		sa(*a, 1);
		ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		rra(a, 1);
}

void	radix_sort(t_list **a, t_list **b)
{
	int	max_bits;
	int	max_index;
	int	size;
	int	bit;
	int	i;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = ps_lstsize(*a);
	max_index = get_max_index(*a);
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index >> bit) & 1) == 1)
				ra(a, 1);
			else
				pb(b, a);
			i++;
		}
		while (*b)
			pa(b, a);
		bit++;
	}
}
