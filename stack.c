/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:04:01 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/27 22:11:44 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_front(t_node **stack, int value, int index)
{
	t_node	*curr;
	t_node	*last;

	if (*stack == NULL)
		*stack = init_stack(value);
	else
	{
		curr = init_stack(value);
		last = find_last(*stack);
		last->next = curr;
	}
	(*stack)->index = index;
}

void	push_back(t_node **stack, int value, int index)
{
	t_node	*curr;

	if (*stack == NULL)
		*stack = init_stack(value);
	else
	{
		curr = init_stack(value);
		curr->next = *stack;
		*stack = curr;
	}
	(*stack)->index = index;
}

void	pop(t_node **stack)
{
	t_node	*tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

t_node	*find_last(t_node *stack)
{
	t_node	*last;

	last = NULL;
	if (stack)
	{
		last = stack;
		while (last->next)
			last = last->next;
	}
	return (last);
}

t_node	*find_pre_last(t_node *stack)
{
	t_node	*pre_last;

	pre_last = NULL;
	if (stack && stack->next)
	{
		pre_last = stack;
		while (pre_last->next->next)
			pre_last = pre_last->next;
	}
	return (pre_last);
}
