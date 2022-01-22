#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include "stack.h"


long	ft_atoi(const char *str);
size_t	ft_stack_len(t_node *stack);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
void	print_stack(t_node *stack);
int		*stack_to_arr(int len, t_node *stack);
void	bubble_sort(int *a, int n);
void	fill_index(t_node **stack, int *arr, int len);
t_node	*fill_stack(int argc, char **argv);
void	p_swap(t_node **stack_a, int len);
void    exec_rotate(t_node **s_a, t_node **s_b, int num);
void    exec_rev_rotate(t_node **s_a, t_node **s_b, int num);
void    exec_swap(t_node **s_a, t_node **s_b, int num);
void    exec_push(t_node **s_a, t_node **s_b, int num);
void    small_sort(t_node **stack_a);
int		find_min(int *arr, int len);
int		find_max(int *arr, int len);
int		find_median(int *arr, int len);
#endif