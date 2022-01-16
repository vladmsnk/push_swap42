#include "push_swap_lib.h"

void	fill_index(t_node **stack, int *arr, int len)
{
	int		i;
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->value == arr[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}