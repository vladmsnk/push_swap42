#include <assert.h>
#include "stack.h"

void should_init_stack()
{
    t_node *node = init_stack(5);
    assert(node->value == 5);
    assert(node->next == NULL);
}

int main() {
    should_init_stack();
}