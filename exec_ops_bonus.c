/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:31:27 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/29 17:31:48 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "checker.h"

void	exec_rotate_bon(t_node **s_a, t_node **s_b, int num)
{
	if (num == 1)
		rotate(s_a);
	else if (num == 2)
		rotate(s_b);
	else if (num == 3)
	{
		rotate(s_a);
		rotate(s_b);
	}
}

void	exec_rev_rotate_bon(t_node **s_a, t_node **s_b, int num)
{
	if (num == 1)
		reverse_rotate(s_a);
	else if (num == 2)
		reverse_rotate(s_b);
	else if (num == 3)
	{
		reverse_rotate(s_a);
		reverse_rotate(s_b);
	}
}

void	exec_swap_bon(t_node **s_a, t_node **s_b, int num)
{
	if (num == 1)
		swap(s_a);
	else if (num == 2)
		swap(s_b);
	else if (num == 3)
	{
		swap(s_a);
		swap(s_b);
	}
}

void	exec_push_bon(t_node **s_a, t_node **s_b, int num)
{
	if (num == 1)
		push_from_to(s_a, s_b);
	else if (num == 2)
		push_from_to(s_b, s_a);
}
