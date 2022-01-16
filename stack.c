#include "stack.h"


t_node	*init_stack(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return node;
}


void	push_back(t_node **stack, int value)
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
}

void	pop(t_node **stack)
{
	t_node *tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}


void	clean_stack(t_node **stack)
{
	t_node *tmp;
	t_node *curr;

	if (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			curr = tmp;
			tmp = tmp->next;
			free(curr);
		}
		*stack = NULL;
	}
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
		push_back(stack2, (*stack1)->value);
		pop(stack1);
	}
}

t_node	*find_last(t_node *stack)
{
	t_node *last;

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

void	rotate(t_node **stack)
{
	t_node *last;
	t_node *tmp;

	if (*stack)
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
	t_node *pre_last;
	t_node	*last;
	t_node *tmp;

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