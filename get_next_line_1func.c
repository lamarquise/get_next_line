/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/08 18:58:28 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)		// add **buff and a warping funk for lists
{
	static char	*t[1000000];
	char	b[BUFF_SIZE + 1];
	int		l;
	char	*p;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (!t[fd] && !(t[fd] = ft_strnew(1))))
		return (-1);
	if ((l = ft_findchar(t[fd], DELIM)) != -1)
	{
		if (!(*line = ft_strsub(t[fd], 0, l++)) ||
			!(p = ft_strsub(t[fd], l, ft_strlen(t[fd]) - l)))
			return (-1);
		free(t[fd]);
		t[fd] = p;
		return (1);
	}
	ft_bzero(b, BUFF_SIZE + 1);	
	if ((l = read(fd, b, BUFF_SIZE)) < 0 || (l > 0 && !(p = ft_strjoin(t[fd], b))) || (t[fd][0] && ++l == 1 && !(p = ft_strjoin(t[fd], "\n"))))
			return (-1);
	free(t[fd]);
	t[fd] = p;
	return ((l > 0) ? get_next_line(fd, line) : 0);
}



/*
	if ((l = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	if (l > 0)
	{
		if (!(tmp = ft_strjoin(t[fd], buff)))
			return (-1);
//		free(t[fd]);
//		t[fd] = tmp;
	}
	else if (l == 0 && t[fd][0]) //&& ft_strlen(t[fd]) > 0 && t[fd][ft_strlen(t[fd]) - 1])
	{
		l = 1;
		if (!(tmp = ft_strjoin(t[fd], "\n")))
			return (-1);
//		free(t[fd]);
//		t[fd] = tmp;
	}
	free(t[fd]);
	t[fd] = tmp;
	if (l > 0)
		return (get_next_line(fd, line));
	return (0);
}
*/


