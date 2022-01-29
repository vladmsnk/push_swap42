/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:28:26 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/29 17:31:02 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		exec_push_bon(stack_a, stack_b, 2);
	else if (!ft_strncmp(op, "pb", len - 1))
		exec_push_bon(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "sa", len - 1))
		exec_swap_bon(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "sb", len - 1))
		exec_swap_bon(stack_a, stack_b, 2);
	else if (!ft_strncmp(op, "ra", len - 1))
		exec_rotate_bon(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "rb", len - 1))
		exec_rotate_bon(stack_a, stack_b, 2);
	else if (!ft_strncmp(op, "rra", len - 1))
		exec_rev_rotate_bon(stack_a, stack_b, 1);
	else if (!ft_strncmp(op, "rrb", len - 1))
		exec_rev_rotate_bon(stack_a, stack_b, 2);
}

int	is_command(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n' && len > 1)
	{
		len--;
		if (!ft_strncmp(str, "pa", len) || !ft_strncmp(str, "pb", len)
			|| !ft_strncmp(str, "sa", len) || !ft_strncmp(str, "sb", len)
			|| !ft_strncmp(str, "ra", len) || !ft_strncmp(str, "rb", len)
			|| !ft_strncmp(str, "rra", len) || !ft_strncmp(str, "rrb", len))
			return (1);
	}
	return (0);
}

int	check_stack(t_node **stack_a, t_node **stack_b, int *arr, int len)
{
	int		flag;
	char	*op;

	flag = 0;
	while (flag != 1)
	{
		op = get_next_line(0);
		if (op == NULL)
			flag = 1;
		else if (!is_command(op))
		{
			clean_stack(stack_a);
			clean_stack(stack_b);
			free(op);
			return (0);
		}
		else
		{
			if (is_command(op))
				apply_ops(stack_a, stack_b, op);
			free(op);
		}
	}
	return (check_stack_sorted(*stack_a, *stack_b));
}

int	main(int argc, char **argv)
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
		exit(1);
	}
	if (check_stack(&stack_a, &stack_b, arr, argc - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(1);
	return (0);
}
