/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:37:04 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/28 17:20:06 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*arr;

	if (argc < 2)
		exit(1);
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		exit(1);
	stack_a = fill_stack(argc, argv, arr);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		write(1, "Error\n", 6);
		free(arr);
		exit(1);
	}
	p_swap(&stack_a, &stack_b, argc - 1, arr);
	free(arr);
	free(stack_b);
	exit(1);
	return (0);
}
