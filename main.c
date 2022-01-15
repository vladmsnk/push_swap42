#include "stack.h"
#include "push_swap_lib.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
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
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		if (!check_str(argv[i]))
			return (NULL);
		push_back(&stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}


int main(int argc, char **argv)
{
	t_node	*stack;

	stack = fill_stack(argc, argv);
	if (stack == NULL)
		printf("%s\n", "Error");
	print_stack(stack);
	
}