/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:48:10 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/27 21:48:11 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

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
