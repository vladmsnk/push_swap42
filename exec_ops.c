#include "push_swap_lib.h"

void    exec_rotate(t_node **s_a, t_node **s_b, int num)
{
    if (num == 1)
    {
        rotate(s_a);
        write(1, "ra\n", 3);
    }
    else if (num == 2)
    {
        rotate(s_b);
        write(1, "rb\n", 3);
    }
    else if (num == 3)
    {
        rotate(s_a);
        rotate(s_b);
        write(1, "rr\n", 3);
    }
    else
        write(1,"smth wrong\n",11);
}

void    exec_rev_rotate(t_node **s_a, t_node **s_b, int num)
{
    if (num == 1)
    {
        reverse_rotate(s_a);
        write(1, "rra\n",4);
    }
    else if (num == 2)
    {
        reverse_rotate(s_b);
        write(1, "rrb\n", 4);
    }
    else if (num == 3)
    {
        reverse_rotate(s_a);
        reverse_rotate(s_b);
        write(1, "rrr\n", 4);
    }
    else
        write(1,"smth wrong\n",11);
}

void    exec_swap(t_node **s_a, t_node **s_b, int num)
{
    if (num == 1)
    {
        swap(s_a);
        write(1, "sa\n", 3);
    }
    else if (num == 2)
    {
        swap(s_b);
        write(1, "sb\n", 3);
    }
    else if (num == 3)
    {
        swap(s_a);
        swap(s_b);
        write(1, "ss\n", 3);
    }
    else
        write(1,"smth wrong\n",11);
}

void    exec_push(t_node **s_a, t_node **s_b, int num)
{
     if (num == 1)
    {
        push_from_to(s_a, s_b);
        write(1, "pa\n", 3);
    }
    else if (num == 2)
    {
        push_from_to(s_b, s_a);
        write(1, "pb\n", 3);
    }
}