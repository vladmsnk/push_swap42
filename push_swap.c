#include "push_swap_lib.h"

void	p_swap(t_node **stack_a, int len)
{
	int	*arr;

	arr = stack_to_arr(len, *stack_a);
	fill_index(stack_a, arr, len);

	return;
}

int main()
{
	t_node	*stack_a;
	int		len;

	stack_a = NULL;
	push_back(&stack_a, 1);
	push_back(&stack_a, 2);
	push_back(&stack_a, 3);
	push_back(&stack_a, 4);
	len = ft_stack_len(stack_a);
	p_swap(&stack_a, len);
	print_stack(stack_a);
}