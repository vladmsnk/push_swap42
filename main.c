#include "push_swap_lib.h"


int	check_str(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


t_node	*fill_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (!check_str(argv[i]))
				return (NULL);
			push_back(&stack, ft_atoi(argv[i]), -1);
			i++;
		}
	}
	return (stack);
}

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	// int	count;

	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	// print_stack(stack_a);
	if (stack_a == NULL)
	{
		write(1,"Error\n", 6);
		return (-1);
	}
	p_swap(&stack_a,&stack_b, argc - 1);
	// count = count_ops_to_add(stack_a, 3, 12);
	// p_swap(&stack_a, argc - 1);
	print_stack(stack_a);
	// count = count_ops_to_add(stack_a, 4, 3);
	// printf("%d\n", count);
}