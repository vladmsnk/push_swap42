#include "push_swap_lib.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		exec_swap(stack_a, NULL, 1);
}


void	p_swap(t_node **stack_a, t_node **stack_b, int len, int *arr)
{

	if (check_sorted(arr, len))
		return;
	if (len == 2)
	{
		sort_two(stack_a);
		return;
	}
	bubble_sort(arr,len);
	fill_index(stack_a, arr, len);
	if (len == 3)
		small_sort(stack_a);
	else if (len <= 5)
		medium_sort(stack_a, stack_b, len);
	else if (len <= 100)
		big_sort(stack_a, stack_b, len, 15);
	else
		big_sort(stack_a, stack_b, len, 30);
}

// int main()
// {
	
// }