#include "push_swap_lib.h"

int	count_ops_to_add_from_front(t_node	*stack_a, int curr_len, int value)
{
	int arr	[curr_len + 1];
	t_node	*tmp;
	int		t;
	int		count;

	t = 0;
	count = 0;
	arr[t++] = value;
	tmp = stack_a;
	while (t < curr_len + 1)
	{
		arr[t++] = tmp->value;
		tmp = tmp->next;
	}
	while (!check_sorted(arr, curr_len + 1))
	{
		t = arr[count];
		arr[count] = arr[count + 1];
		arr[count + 1] = t;
		count++;
	}
	return (count);
}

// int	count_ops_to_add_from_back(t_node	*stack_a, int curr_len, int value)
// {
// 	int arr	[curr_len + 1];
// 	t_node	*tmp;
// 	int		t;
// 	int		count;

// 	t = 0;
// 	count = 0;
// 	while (t < curr_len)
// 	{
// 		arr[t++] = tmp->value;
// 		tmp = tmp->next;
// 	}
// 	arr[t] = value;
// 	while (!check_sorted(arr, curr_len + 1))
// 	{
// 		t = arr[curr_len + 1 - count];
// 		arr[curr_len + 1 - count] = arr[curr_len - count];
// 		arr[curr_len - count] = t;
// 		count++;
// 	}
// 	return (count);
// }

// t_node	*find_max(t_node *stack)
// {
// 	int	curr;

// 	curr = stack;
// 	while (stack)
// }

int	find_cost(t_node *stack_b, int index)
{
	int	steps;

	steps = 0;
	if (stack_b)
	{
		while (stack_b->index != index)
		{
			steps++;
			stack_b = stack_b->next;
		}
	}
	return (steps);
}


void	big_sort_final(t_node **stack_a, t_node **stack_b, int len)
{
	int	curr_max_ind;
	int	median;
	int	cost;

	curr_max_ind = len - 1;
	while (*stack_b)
	{
		median = curr_max_ind / 2;
		cost = find_cost(*stack_b, curr_max_ind);
		if (!cost)
		{
			exec_push(stack_a, stack_b, 2);
			curr_max_ind--;
		}
		else if (cost < median)
			exec_rotate(stack_a, stack_b, 2);
		else
			exec_rev_rotate(stack_a, stack_b, 2);
	}
}


void    small_sort(t_node **stack_a)
{
    t_node  *tmp;
    t_node  *last;

    tmp = *stack_a;
    last = find_last(*stack_a);
    if (last->value > tmp->value && tmp->next->value < tmp->value)
        exec_swap(stack_a, NULL, 1);
    else if (last->value < tmp->next->value && tmp->value > tmp->next->value)
    {
        exec_swap(stack_a, NULL, 1);
        exec_rev_rotate(stack_a, NULL, 1);
    }
    else if (last->value < tmp->value && tmp->next->value < last->value)
        exec_rotate(stack_a, NULL, 1);
    else if (tmp->next->value > last->value && tmp->value < last->value)
    {
        exec_swap(stack_a, NULL, 1);
        exec_rotate(stack_a, NULL, 1);
    }
    else if (tmp->value < tmp->next->value && last->value < tmp->value)
        exec_rev_rotate(stack_a, NULL, 1);
}

void	medium_sort(t_node  **stack_a, t_node **stack_b, int len)
{
	int	tmp;
	int index;

	tmp = len;
	while (tmp > 3)
	{	
		index = (*stack_a)->index ;
		if ((*stack_a)->index == 0 || (*stack_a)->index == len - 1)
		{
			exec_push(stack_a, stack_b, 1);
			tmp--;
		}
		else
			exec_rotate(stack_a, NULL, 1);
	}
	small_sort(stack_a);
	while (tmp - 1 > 0)
	{
		if ((*stack_b)->index  == 0)
			exec_push(stack_a, stack_b, 2);
		else if ((*stack_b)->index == len - 1)
		{
			exec_push(stack_a, stack_b, 2);
			exec_rotate(stack_a, NULL, 1);
		}
		tmp--;
	}
}


void	big_sort(t_node	**stack_a, t_node **stack_b, int len, int range)
{
	int	tau;

	tau = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= tau && tau > 1)
		{
			exec_push(stack_a, stack_b, 1);
			exec_rotate(stack_a, stack_b, 2);
			tau++;
		}
		else if ((*stack_a)->index < range + tau)
		{
			exec_push(stack_a, stack_b, 1);
			tau++;
		}
		else
			exec_rotate(stack_a, stack_b, 1);
	}
	big_sort_final(stack_a, stack_b, len);
}