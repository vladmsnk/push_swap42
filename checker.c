#include "push_swap_lib.h"
#include "checker.h"

int	check_stack_sorted(t_node *stack_a, t_node *stack_b)
{
	t_node	*curr;

	if (stack_b != NULL)
		return (0);
	if (stack_a->next == NULL)
		return (1);
	curr = stack_a;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	apply_ops(t_node **stack_a, t_node **stack_b, char *op)
{
	int	len;

	len = ft_strlen(op);
	if (!ft_strncmp(op, "pa", len - 1))
		exec_push(stack_a, stack_b, 2);
	else if (!ft_strncmp(op, "pb", len - 1))
		exec_push(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "sa", len - 1))
		exec_swap(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "sb", len - 1))
		exec_swap(stack_a, stack_b, 2);
	else if (!ft_strncmp(op, "ra", len - 1))
		exec_rotate(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "rb", len - 1))
		exec_rotate(stack_a, stack_b, 2);
	else if (!ft_strncmp(op, "rra", len - 1))
		exec_rev_rotate(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "rrb", len - 1)) 
		exec_rev_rotate(stack_a, stack_b, 2);
}

int	is_command(char *str)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		if (str[len - 1] == '\n' && len > 1)
		{
			len--;
			if (!ft_strncmp(str, "pa", len) || !ft_strncmp(str, "pb", len) || !ft_strncmp(str, "sa", len) ||
					!ft_strncmp(str, "sb", len) || !ft_strncmp(str, "ra", len) || !ft_strncmp(str, "rb", len) || 
						!ft_strncmp(str, "rra", len) || !ft_strncmp(str, "rrb", len))
				return (1);
		}
		else if (str[len - 1] == '\n')
			return (1);
	}
	return (0);
}

int	check_stack(t_node **stack_a, t_node **stack_b, int *arr, int len)
{
	int		flag;
	char	*tmp;

	flag = 0;
	while (!flag)
	{
		tmp	= get_next_line(0);
		if (tmp && tmp[0] == '\n' && ft_strlen(tmp) == 1)
			flag++;
		if (!is_command(tmp))
		{
			free(tmp);
			return (0);
		}
		else
			apply_ops(stack_a, stack_b, tmp);
		free(tmp);
	}
	if (check_stack_sorted(*stack_a, *stack_b))
		return (1);
	return (0);
}

// t_node	*fill_stack_and_arr(int argc, char **argv, int *arr)
// {
// 	t_node	*stack;
// 	int		i;
// 	int		val;

// 	i = 1;
// 	stack = NULL;
// 	while (!ft_strncmp(argv[i], "\n", 1));
// 	{
// 		if (!check_str(argv[i]))
// 		{
// 			clean_stack(&stack);
// 			return (NULL);
// 		}
// 		val = ft_atoi(argv[i]);
// 		push_front(&stack, val, -1);
// 		arr[i - 1] = val;
// 		i++;
// 	}
// 	if (check_duplicate(arr, argc - 1))
// 	{
// 		clean_stack(&stack);
// 		return (NULL);
// 	}
// 	return (stack);
// }

// int	check_input(char **argv, int *arr)
// {
// 	int	n_cnt;
// 	int	i;

// 	n_cnt = 0;
// 	i = 1;
// 	while (ft_strncmp(argv[i], "\n", 1))
// 	{
// 		if (!check_str(argv[i]) && ft_strncmp(argv[i], "\n", 1))
// 			return (0);
// 		arr[i - 1] = ft_atoi(argv[i]);
// 		i++;
// 	}
// 	return (1);
// }

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*arr;

	if (argc < 2)
		exit(1);
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		exit(1);
	stack_a = fill_stack(argc, argv, arr);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		write(1, "Error\n", 6);
		free(arr);
		exit(1);
	}
	if (check_stack(&stack_a, &stack_b, arr, argc - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(1);
	return (0);
}
