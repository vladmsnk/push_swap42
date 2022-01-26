#include "push_swap_lib.h"




void	p_swap(t_node **stack_a, t_node **stack_b, int len)
{
	int	*arr;

	arr = stack_to_arr(len, *stack_a);
	// if (check_sorted(arr, len))
	// 	return;
	fill_index(stack_a, arr, len);
	if (len == 3)
		small_sort(stack_a);
	else if (len <= 5)
		medium_sort(stack_a, stack_b, len);
	else if (len <= 100)
		big_sort(stack_a, stack_b, len, 15);
	else
		big_sort(stack_a, stack_b, len, 30);
	return;
}

// int main()
// {
	
// }