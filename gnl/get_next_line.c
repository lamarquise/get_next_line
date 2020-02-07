/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2020/02/07 18:37:13 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>		// REMOVE !!!!!!!!

#include "get_next_line.h"

static int		gnl(int fd, char **line)
{
	static char		*s;		// could this be the free problem...
	ssize_t			i;
	char			*p;
	char			b[BUFFER_SIZE + 1];		// or maybe its this, the buffer never gets freed cuz its fixed and contained in the funtion



/*	char			*b;

	b = NULL;
	if (!(b = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ft_bzero(b, BUFFER_SIZE + 1);

*/


//	printf("test 1\n");
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
	if (!line || !ft_bzero(b, BUFFER_SIZE + 1)
		|| (i = read(fd, b, BUFFER_SIZE)) < -1 
//		|| !printf("i = %zd\n", i)
		|| (i > 0 && !(p = ft_strjoin(&s, b)))		// it might be the way i set this condition up... like the reason i never saw a segfault before 
		|| (s && s[0] && ++i == 1 && !(*line = ft_strjoin(&s, "")))		// wait hold on this may be the one that fucks up...
		|| (i < 1 && !(*line) && !(*line = ft_strsub(NULL, 0, 0))) || i < 0		// )
			)
	{
//		free(b);
		return (-1);
	}
	if (i > 0)
	{
//		if (p[0] == '\0')		// more conditions ????
//			return (0);
		free(s);
		s = p;
//		free(p);
	}
//	free(p);
//	free(b);
	return ((i > 0) ? gnl(fd, line) : 0);
}

int				get_next_line(int fd, char **line)
{
	if (line)
		*line = NULL;
	return (gnl(fd, line));
}
