#include "push_swap_lib.h"


void    small_sort(t_node **stack_a)
{
    t_node  *tmp;
    t_node  *last;

    tmp = *stack_a;
    last = find_last(*stack_a);
    if (last->value > tmp->value && tmp->next->value < tmp->value)
        exec_swap(stack_a, NULL, 1);
    else if (last->value < tmp->next->value && tmp->value > tmp->next->value)
    {
        exec_swap(stack_a, NULL, 1);
        exec_rev_rotate(stack_a, NULL, 1);
    }
    else if (last->value < tmp->value && tmp->next->value < last->value)
        exec_rotate(stack_a, NULL, 1);
    else if (tmp->next->value > last->value && tmp->value < last->value)
    {
        exec_swap(stack_a, NULL, 1);
        exec_rotate(stack_a, NULL, 1);
    }
    else if (tmp->value < tmp->next->value && last->value < tmp->value)
        exec_rev_rotate(stack_a, NULL, 1);
}