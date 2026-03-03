#include "push_swap.h"
#include <stdlib.h>

int	check_dupli(t_list *a)
{
	t_list	*curr;
	t_list	*scan;

	curr = a;
	while (curr)
	{
		scan = curr->next;
		while (scan)
		{
			if (scan->value == curr->value)
				return (1);
			scan = scan->next;
		}
		curr = curr->next;
	}
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}
