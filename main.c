#include "push_swap_lib.h"


// void	execute_rules_from_stdin()
// {
// 	t_node	*stack;



// }

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
			push_back(&stack, ft_atoi(argv[i]));
			i++;
		}
	}
	return (stack);
}

// int main(int argc, char **argv)
// {
// 	t_node	*stack_a;

// 	stack_a = fill_stack(argc, argv);
// 	if (stack_a == NULL)
// 	{
// 		write(1,"Error\n", 6);
// 		return (-1);
// 	}
// 	p_swap(stack_a, argc - 1);
// 	// print_stack(stack);
// }