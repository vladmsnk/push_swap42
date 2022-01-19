#include "push_swap_lib.h"




void	p_swap(t_node **stack_a, int len)
{
	int	*arr;

	arr = stack_to_arr(len, *stack_a);
	fill_index(stack_a, arr, len);
	if (len == 3)
		small_sort(stack_a);
	return;
}

// int main()
// {
	
// }