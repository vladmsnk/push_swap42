/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:48:10 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/28 16:58:00 by jjhezane         ###   ########.fr       */
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
	while (argv[i])
	{
		if (!check_str(argv[i]))
		{
			clean_stack(&stack);
			return (NULL);
		}
		val = ft_atoi(argv[i]);
		push_front(&stack, val, -1);
		arr[i - 1] = val;
		i++;
	}
	if (check_duplicate(arr, argc - 1))
	{
		clean_stack(&stack);
		return (NULL);
	}
	return (stack);
}

void	fill_index(t_node **stack, int *arr, int len)
{
	int		i;
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->value == arr[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}
