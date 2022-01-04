#include "stack.h"


t_node	*init_stack(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
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

void	print_stack(t_node *stack)
{
	t_node *top = stack;
	if (top)
	{
		while (top)
		{
			printf("%d ---> ", top->value);
			top = top->next;
		}
		printf("%p", NULL);
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
	t_node *tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		
	}
}