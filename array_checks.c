/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:39:44 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/29 17:22:10 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	clean_stack(t_node	**stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	check_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	if (len == 1)
		return (1);
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
