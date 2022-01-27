/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:37:04 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/27 21:37:05 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	check_duplicate(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (0);
	if ((str[i] != '-') && (str[i] < '0' || str[i] > '9'))
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_node	*fill_stack(int argc, char **argv, int *arr)
{
	t_node	*stack;
	int		i;
	int		val;

	i = 1;
	stack = NULL;
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (!check_str(argv[i]))
				return (NULL);
			val = ft_atoi(argv[i]);
			push_front(&stack, val, -1);
			arr[i - 1] = val;
			i++;
		}
	}
	if (check_duplicate(arr, argc - 1))
		return (NULL);
	return (stack);
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
	p_swap(&stack_a, &stack_b, argc - 1, arr);
	free(arr);
	free(stack_b);
	return (0);
}
