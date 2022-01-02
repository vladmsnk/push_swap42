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



#endif  