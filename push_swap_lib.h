#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include "stack.h"

long	ft_atoi(const char *str);
size_t	ft_stack_len(t_node *stack);
void	print_stack(t_node *stack);
// void	print_stacks(t_node *stack_a, t_node *stack_b);
int		*stack_to_arr(int len, t_node *stack);
char	*ft_itoa(int n);
void	bubble_sort(int *a, int n);
void	ft_putnbr_fd(int n, int fd);
void	fill_index(t_node **stack, int *arr, int len);
#endif