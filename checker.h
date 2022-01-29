/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:31:16 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/29 17:31:17 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	exec_rotate_bon(t_node **s_a, t_node **s_b, int num);
void	exec_rev_rotate_bon(t_node **s_a, t_node **s_b, int num);
void	exec_swap_bon(t_node **s_a, t_node **s_b, int num);
void	exec_push_bon(t_node **s_a, t_node **s_b, int num);

#endif  