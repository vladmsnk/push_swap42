#include "push_swap_lib.h"

int	*stack_to_arr(int len, t_node *stack)
{
	int		*array;
	int		i;
	t_node	*tmp;

	tmp = stack;
	i = 0;
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (i < len)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(array, len);
	return (array);
}

// void	print_array(int *arr, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
		
// 	}
// }

void	print_stack(t_node *stack)
{
	t_node *top = stack;
	if (top)
	{
		while (top)
		{
			printf("%d ---> ", top->value);
			top = top->next;
		}
		printf("NULL\n");
	}
}

// int main()
// {
// 	t_node	*stack;
// 	int		len;
// 	int		*arr;

// 	stack = NULL;
// 	push_back(&stack, 1);
// 	push_back(&stack, 4);
// 	push_back(&stack, 2);
// 	push_back(&stack, 3);
// 	push_back(&stack, 2);
// 	push_back(&stack, 4);
// 	len = ft_stack_len(stack);
// 	arr = stack_to_arr(len, stack);
// 	for (int i =0; i < len; i++)
// 		printf("%d\n", arr[i]);
// 	// print_arr(arr);
// 	// printf("%s\n", arr[0]);
// 	// printf("%s\n", arr[1]);
// 	// printf("%s\n", arr[2]);
// }