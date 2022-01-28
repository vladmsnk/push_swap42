/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:40:23 by jjhezane          #+#    #+#             */
/*   Updated: 2022/01/28 19:13:08 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_rem(char *line)
{
	size_t	idx;
	char	*new_line;

	new_line = NULL;
	if (line)
	{
		if (!ft_strchr(line, '\n'))
			return (NULL);
		idx = ft_strchr(line, '\n') - line;
		new_line = ft_sub(line, 0, idx + 1);
	}
	return (new_line);
}

char	*create_empty(void)
{
	char	*new_line;

	new_line = (char *)malloc(sizeof(char));
	if (!new_line)
		return (NULL);
	new_line[0] = '\0';
	return (new_line);
}

char	*update_rem(char *line)
{
	char	*cpy;
	size_t	ind;

	if (ft_strchr(line, '\n'))
	{
		ind = ft_strchr(line, '\n') - line;
		cpy = ft_sub(line + ind + 1, 0, ft_len(line + ind + 1));
		free(line);
		return (cpy);
	}
	free(line);
	return (NULL);
}

char	*create_line(char *line, char *buff, int fd)
{
	int			rd;

	rd = 2;
	while (!ft_strchr(line, '\n') && rd != 0)
	{
		rd = read(fd, buff, 2);
		buff[rd] = '\0';
		line = ft_strjoin(line, buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buff[2];
	static char	*rem;
	char		*gtn_ln;

	if (read(fd, buff, 0) < 0)
		return (NULL);
	gtn_ln = check_rem(rem);
	if (!gtn_ln)
	{	
		if (!rem)
			rem = create_empty();
		rem = create_line(rem, buff, fd);
		if (ft_strchr(rem, '\n'))
			gtn_ln = ft_sub(rem, 0, ft_strchr(rem, '\n') - rem + 1);
		else
			gtn_ln = ft_sub(rem, 0, ft_len(rem));
	}
	rem = update_rem(rem);
	if (!ft_len(gtn_ln))
	{
		free(gtn_ln);
		return (NULL);
	}
	return (gtn_ln);
}
