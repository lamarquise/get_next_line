/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/12/04 18:28:35 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			gnl(int fd, char **line)
{
	ssize_t			i;
	static char		b[BUFFER_SIZE + 1];
	char			*p;

	p = NULL;
	if ((i = ft_findchar(*line, '\n')) != -1)
	{
		if (!(p = ft_strsub(*line, 0, (size_t)i++)))
			return (-1);
		ft_bzero(b, sizeof(b));
		while ((*line)[i] && ft_strlen(b) < BUFFER_SIZE)
			b[ft_strlen(b)] = (*line)[i++];
		free(*line);
		*line = p;
		return (1);
	}
	if (!line || (!(*line) && !(*line = ft_strsub(b, 0, ft_strlen(b))))
		|| !ft_bzero(b, sizeof(b)) || (i = read(fd, b, BUFFER_SIZE)) < 0
		|| (i > 0 && !(ft_strjoin(line, b))))
		return (-1);
	return ((i > 0 || (ft_findchar(*line, '\n') != -1)) ? gnl(fd, line) : 0);
}

int			get_next_line(int fd, char **line)
{
	if (line)
		*line = NULL;
	return (gnl(fd, line));
}
