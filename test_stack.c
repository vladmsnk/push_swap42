#include <assert.h>
#include "stack.h"

// void should_init_stack()
// {
//     t_node *node = init_stack(5);
//     assert(node->value == 5);
//     assert(node->next == NULL);
//     free(node);
// }


// void should_clean_stack()
// {
//     t_node *stack;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     push_back(&stack,3);
//     push_back(&stack,4);
//     push_back(&stack,5);
//     clean_stack(&stack);
//     assert(stack == NULL);
// }


// void should_push_back()
// {
//     t_node *node = init_stack(5);

//     push_back(&node, 6);
//     assert(node->value == 6);
//     assert(node->next->value == 5);
//     clean_stack(&node);
// }

// void should_print_stack()
// {
//     t_node *stack;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     push_back(&stack,3);
//     push_back(&stack,4);
//     push_back(&stack,5);
//     print_stack(stack);
//     clean_stack(&stack);
// }

// void should_pop()
// {
//     t_node *stack;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     assert(stack->value == 2);
//     pop(&stack);
//     assert(stack->value == 1);
//     clean_stack(&stack);
// }


// void should_swap()
// {
    
// 	t_node *stack;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     push_back(&stack,3);
//     push_back(&stack,4);
//     push_back(&stack,5);
// 	swap(&stack);
// 	assert(stack->value == 4);
// 	assert(stack->next->value == 5);
// 	assert(stack->next->next->value == 3);
// 	clean_stack(&stack);
// }

// void	should_push_from_to()
// {
// 	t_node *stack1;
// 	t_node *stack2;

//     push_back(&stack1,1);
//     push_back(&stack1,2);
//     push_back(&stack1,3);
//     push_back(&stack1,4);
//     push_back(&stack1,5);
// 	push_from_to(&stack1, &stack2);
// 	assert(stack1->value == 4);
// 	assert(stack2->value == 5);
//     clean_stack(&stack1);
//     clean_stack(&stack2);
// }
// void	should_find_last()
// {
// 	t_node *stack;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     push_back(&stack,3);
//     push_back(&stack,4);
//     push_back(&stack,5);

// 	t_node *last = find_last(stack);
    
// 	assert(last->value == 1);
//     clean_stack(&stack);
// }

// void	should_find_pre_last()
// {
// 	t_node *stack;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     push_back(&stack,3);
//     push_back(&stack,4);
//     push_back(&stack,5);

// 	t_node *pre_last = find_pre_last(stack);
// 	assert(pre_last->value == 2);
//     clean_stack(&stack);
// }

// void    should_rotate()
// {
//     t_node  *stack_1;
//     t_node  *last;

//     push_back(&stack_1,1);
//     push_back(&stack_1,2);
//     push_back(&stack_1,3);
//     push_back(&stack_1,4);
//     push_back(&stack_1,5);

//     rotate(&stack_1);
//     last = find_last(stack_1);
//     assert(last->value == 5);
//     assert(stack_1->value == 4);
//     clean_stack(&stack_1);
// }

// void    should_reverse_rotate()
// {
//     t_node *stack;
//     t_node  *last;

//     push_back(&stack,1);
//     push_back(&stack,2);
//     push_back(&stack,3);
//     push_back(&stack,4);
//     push_back(&stack,5);
//     reverse_rotate(&stack);
//     last = find_last(stack);
//     assert(stack->value == 1);
//     assert(last->value == 2);
//     clean_stack(&stack);
// }

int main() {
    // should_init_stack();
    // should_push_back();
    // should_clean_stack();
    // // // should_print_stack();
    // should_pop();
	// should_swap();
	// should_push_from_to();
	// should_find_last();
    // should_find_pre_last();
    // should_rotate();;
    // should_reverse_rotate();
    // printf("%s\n", "Ok");
}