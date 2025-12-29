#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

int	check_dupli(t_list *a)
{
	t_list *tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}