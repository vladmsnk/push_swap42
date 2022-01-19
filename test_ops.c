#include "push_swap_lib.h"
#include "assert.h"

void assert_stack(t_node *stack_a,t_node *stack_b, int beg_a,
                         int beg_b, int end_a, int end_b)
{
    t_node  *last_a;
    t_node  *last_b;

    last_a= find_last(stack_a);
    last_b= find_last(stack_b);

    assert(stack_a->value == beg_a);
    assert(stack_b->value == beg_b);
    assert(last_a->value == end_a);
    assert(last_b->value == end_b);
}

void    should_exec_rotate()
{
    t_node	*stack_a;
	t_node	*stack_b;

    printf("%s\n", "test_1");
	stack_a = NULL;
	stack_b = NULL;
	push_back(&stack_a, 1);
	push_back(&stack_a, 2);
	push_back(&stack_a, 3);
	push_back(&stack_a, 4);

	push_back(&stack_b, 5);
	push_back(&stack_b, 6);
	push_back(&stack_b, 7);

    exec_rotate(&stack_a, &stack_b, 1);
    assert_stack(stack_a, stack_b, 3,7,4,5);
    exec_rotate(&stack_a, &stack_b, 2);
    assert_stack(stack_a, stack_b, 3,6,4,7);
    exec_rotate(&stack_a, &stack_b, 3);
    assert_stack(stack_a, stack_b, 2,5,3,6);
    clean_stack(&stack_a);
    clean_stack(&stack_b);
}


void    should_exec_swap()
{
    t_node	*stack_a;
	t_node	*stack_b;

    printf("%s\n", "test_2");
	stack_a = NULL;
	stack_b = NULL;
	push_back(&stack_a, 1);
	push_back(&stack_a, 2);
	push_back(&stack_a, 3);
	push_back(&stack_a, 4);

	push_back(&stack_b, 5);
	push_back(&stack_b, 6);
	push_back(&stack_b, 7);
    exec_swap(&stack_a, &stack_b, 1);
    assert_stack(stack_a, stack_b, 3,7, 1, 5);
    assert(stack_a->next->value == 4);
    exec_swap(&stack_a, &stack_b, 2);
    assert_stack(stack_a, stack_b, 3,6, 1, 5);
    assert(stack_b->next->value == 7);
    exec_swap(&stack_a, &stack_b, 3);
    assert_stack(stack_a, stack_b, 4,7, 1, 5);
    assert(stack_a->next->value == 3);
    assert(stack_b->next->value == 6);
    clean_stack(&stack_a);
    clean_stack(&stack_b);
}

void    should_exec_rev_rotate()
{  
    t_node	*stack_a;
	t_node	*stack_b;

    printf("%s\n", "test_3");
	stack_a = NULL;
	stack_b = NULL;
	push_back(&stack_a, 1);
	push_back(&stack_a, 2);
	push_back(&stack_a, 3);
	push_back(&stack_a, 4);

	push_back(&stack_b, 5);
	push_back(&stack_b, 6);
    push_back(&stack_b, 7);

    exec_rev_rotate(&stack_a, &stack_b, 1);
    assert_stack(stack_a, stack_b, 1,7, 2, 5);
    exec_rev_rotate(&stack_a, &stack_b, 2);
    assert_stack(stack_a, stack_b, 1,5, 2, 6);
    exec_rev_rotate(&stack_a, &stack_b, 3);
    assert_stack(stack_a, stack_b, 2,6, 3, 7);
}

void    should_exec_push()
{
    t_node	*stack_a;
	t_node	*stack_b;

    printf("%s\n", "test_3");
	stack_a = NULL;
	stack_b = NULL;
	push_back(&stack_a, 1);
	push_back(&stack_a, 2);
	push_back(&stack_a, 3);
	push_back(&stack_a, 4);

	push_back(&stack_b, 5);
	push_back(&stack_b, 6);
    push_back(&stack_b, 7);
    exec_push(&stack_a, &stack_b, 1);
    assert_stack(stack_a, stack_b, 3,4, 1, 5);
    assert(ft_stack_len(stack_a) == 3);
    assert(ft_stack_len(stack_b) == 4);
    exec_push(&stack_a, &stack_b, 2);
    assert_stack(stack_a, stack_b, 4,7, 1, 5);
    assert(ft_stack_len(stack_a) == 4);
    assert(ft_stack_len(stack_b) == 3);
}


// int main()
// {
//     should_exec_rotate();
//     should_exec_swap();
//     should_exec_rev_rotate();
//     should_exec_push();
//     printf("%s\n", "tests passed!!");
// }