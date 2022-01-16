#include "push_swap_lib.h"

size_t	ft_stack_len(t_node *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}