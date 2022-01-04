#include <assert.h>
#include "stack.h"

void should_init_stack()
{
    t_node *node = init_stack(5);
    assert(node->value == 5);
    assert(node->next == NULL);
    free(node);
}


void should_clean_stack()
{
    t_node *stack;

    push_back(&stack,1);
    push_back(&stack,2);
    push_back(&stack,3);
    push_back(&stack,4);
    push_back(&stack,5);
    clean_stack(&stack);
    assert(stack == NULL);
}


void should_push_back()
{
    t_node *node = init_stack(5);

    push_back(&node, 6);
    assert(node->value == 6);
    assert(node->next->value == 5);
    clean_stack(&node);
}

void should_print_stack()
{
    t_node *stack;

    push_back(&stack,1);
    push_back(&stack,2);
    push_back(&stack,3);
    push_back(&stack,4);
    push_back(&stack,5);
    print_stack(stack);
    clean_stack(&stack);
}

void should_pop()
{
    t_node *stack;

    push_back(&stack,1);
    push_back(&stack,2);
    assert(stack->value == 2);
    pop(&stack);
    assert(stack->value == 1);
}


int main() {
    should_init_stack();
    should_push_back();
    should_clean_stack();
    // should_print_stack();
    should_pop();
    printf("%s\n", "Ok");
}