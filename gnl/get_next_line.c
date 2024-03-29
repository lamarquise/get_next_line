/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2021/12/09 15:35:00 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 4

static int		gnl(int fd, char **line)
{
	static char		*s;
	ssize_t			i;
	char			*p;
	char			b[BUFFER_SIZE + 1];

	p = NULL;
	if ((i = ft_findchar(s, '\n')) != -1)
	{
		if (!(*line = ft_strsub(s, 0, (size_t)i++))
			|| (!(p = ft_strsub(s, i, ft_strlen(s) - (size_t)i))))
			return (-1);
		free(s);
		s = p;
		return (1);
	}
	if (BUFFER_SIZE <= 0 || !line || !ft_bzero(b, BUFFER_SIZE + 1)
		|| (i = read(fd, b, BUFFER_SIZE)) < -1
		|| (i > 0 && !(p = ft_strjoin(&s, b)))
		|| (s && s[0] && ++i == 1 && !(*line = ft_strjoin(&s, (void*)0)))
		|| (i < 1 && !(*line) && !(*line = ft_strsub(NULL, 0, 0))) || i < 0)
		return (-1);
	free(s);
	s = p;
	return ((i > 0) ? gnl(fd, line) : 0);
}

int				get_next_line(int fd, char **line)
{
	if (line)
		*line = NULL;
	return (gnl(fd, line));
}
