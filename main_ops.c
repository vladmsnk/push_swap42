/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:12:19 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/28 19:35:48 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*init_stack(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	swap(t_node **stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp1 = *stack;
		tmp2 = (*stack)->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*stack = tmp2;
	}
}

void	push_from_to(t_node **stack1, t_node **stack2)
{
	if (*stack1)
	{
		push_back(stack2, (*stack1)->value, (*stack1)->index);
		pop(stack1);
	}
}

void	rotate(t_node **stack)
{
	t_node	*last;
	t_node	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		last = find_last(*stack);
		last->next = tmp;
	}
}

void	reverse_rotate(t_node **stack)
{
	t_node	*pre_last;
	t_node	*last;
	t_node	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		pre_last = find_pre_last(*stack);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*stack = last;
	}
}
