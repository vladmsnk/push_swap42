/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:41:15 by jjhezane          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:17 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (s[len] != '\0')
		{
			len++;
		}
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	iter;
	size_t	exp_len;

	iter = 0;
	exp_len = ft_len(src);
	if (dstsize == 0)
		return (ft_len(src));
	while (iter < dstsize - 1 && src[iter] != '\0')
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[iter] = '\0';
	return (exp_len);
}

char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	iter;

	if (s)
	{
		if (start >= ft_len(s))
		{
			sub_str = (char *)malloc(sizeof(char));
			if (!sub_str)
				return (NULL);
			*sub_str = '\0';
			return (sub_str);
		}
		if (start + len > ft_len(s))
			len = ft_len(s) - start;
		sub_str = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub_str)
			return (NULL);
		iter = 0;
		ft_strlcpy(sub_str, s + start, len + 1);
		return (sub_str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	iter;
	char	*to_out;

	iter = 0;
	if (s)
	{
		while (*(s + iter) != '\0' && *(s + iter) != (char)c)
			iter++;
		if (*(s + iter) == (char)c)
		{
			to_out = (char *)(s + iter);
			return (to_out);
		}
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*jnd;
	char	*cpy;
	size_t	iter;

	if (s1 && s2)
	{
		cpy = s1;
		iter = 0;
		jnd = (char *)malloc((ft_len(s1) + ft_len(s2) + 1) * sizeof(char));
		if (!jnd)
			return (NULL);
		while (*s1 || *s2)
		{
			if (*s1)
				*(jnd + iter++) = *s1++;
			else if (!(*s1) && *s2)
				*(jnd + iter++) = *s2++;
		}
		*(jnd + iter) = '\0';
		free(cpy);
		return (jnd);
	}
	return (NULL);
}
