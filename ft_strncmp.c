/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:32:11 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/29 17:32:16 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			iter;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	iter = 0;
	while (tmp_s1[iter] != '\0' && tmp_s2[iter] != '\0' && iter < n)
	{
		if (tmp_s1[iter] != tmp_s2[iter])
		{
			return ((int)(tmp_s1[iter] - tmp_s2[iter]));
		}
		iter++;
	}
	if (iter == n)
		return (0);
	return ((int)(tmp_s1[iter] - tmp_s2[iter]));
}
