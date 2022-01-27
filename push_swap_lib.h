/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:57:20 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/27 21:58:29 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include "stack.h"

long	ft_atoi(const char *str);
void	bubble_sort(int *a, int n);
void	fill_index(t_node **stack, int *arr, int len);
t_node	*fill_stack(int argc, char **argv, int *arr);
void	p_swap(t_node **stack_a, t_node **stack_b, int len, int *arr);
void	exec_rotate(t_node **s_a, t_node **s_b, int num);
void	exec_rev_rotate(t_node **s_a, t_node **s_b, int num);
void	exec_swap(t_node **s_a, t_node **s_b, int num);
void	exec_push(t_node **s_a, t_node **s_b, int num);
void	small_sort(t_node **stack_a);
int		check_sorted(int *arr, int len);
void	medium_sort(t_node **stack_a, t_node **stack_b, int len);
void	big_sort(t_node	**stack_a, t_node **stack_b, int len, int range);

#endif