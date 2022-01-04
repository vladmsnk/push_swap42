#ifndef SORTS_H
# define SORTS_H


#include <stdlib.h>
#include <stdio.h>


typedef struct s_node
{
	int	value;
	struct s_node *next;
}   t_node;


t_node	*init_stack(int value);
void	push_back(t_node **stack, int value);
void	print_stack(t_node *stack);
void	clean_stack(t_node **stack);
void	pop(t_node **stack);
void	swap(t_node **stack);

#endif  