#include "stack.h"


t_node	*init_stack(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return node;
}
