#include "push_swap.h"
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	append_value(t_list **a, const char *str)
{
	int		error;
	long	value;
	t_list	*node;

	error = 0;
	value = ft_atoi_safe(str, &error);
	if (error)
		return (1);
	node = ps_lstnew((int)value);
	if (!node)
		return (1);
	ps_lstadd_back(a, node);
	return (0);
}

static int	parse_single_arg(const char *arg, t_list **a)
{
	int		i;
	int		j;
	int		k;
	char	*token;
	int		parsed;

	i = 0;
	parsed = 0;
	while (arg[i])
	{
		while (arg[i] && is_space(arg[i]))
			i++;
		if (!arg[i])
			break ;
		j = i;
		while (arg[j] && !is_space(arg[j]))
			j++;
		token = (char *)malloc((j - i + 1) * sizeof(char));
		if (!token)
			return (1);
		k = 0;
		while (i < j)
		{
			token[k] = arg[i];
			i++;
			k++;
		}
		token[k] = '\0';
		if (append_value(a, token) != 0)
			return (free(token), 1);
		free(token);
		parsed = 1;
	}
	if (parsed == 0)
		return (1);
	return (0);
}

int	parse_args_to_stack(int argc, char **argv, t_list **a)
{
	int		i;

	if (!a)
		return (1);
	if (argc == 2)
		return (parse_single_arg(argv[1], a));
	i = 1;
	while (i < argc)
	{
		if (append_value(a, argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
