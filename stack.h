#ifndef SORTS_H
# define SORTS_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
	int	value;
	struct s_node *next;
}   t_node;


t_node	*init_stack(int value);
void	push_back(t_node **stack, int value);
void	clean_stack(t_node **stack);
void	pop(t_node **stack);
void	swap(t_node **stack);
void	push_from_to(t_node **stack1, t_node **stack2);
t_node	*find_last(t_node *stack);
t_node	*find_pre_last(t_node *stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
#endif  