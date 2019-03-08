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
						// First Checks
	if (fd < 0 || !line || BUFF_SIZE < 1 || (!t[fd] && !(t[fd] = ft_strnew(1))))
		return (-1);	// at the first \n
	if ((l = ft_findchar(t[fd], DELIM)) != -1)
	{					// cut everything before the 1st \n
		if (!(*line = ft_strsub(t[fd], 0, l++)) ||
			!(p = ft_strsub(t[fd], l, ft_strlen(t[fd]) - l)))
			return (-1);	// cut everything after the 1st \n
		free(t[fd]);
		t[fd] = p;
		return (1);
	}
	ft_bzero(b, BUFF_SIZE + 1);	// read			// once read join		//if end of file but no \n, add one
	if ((l = read(fd, b, BUFF_SIZE)) < 0 || (l > 0 && !(p = ft_strjoin(t[fd], b))) || (t[fd][0] && ++l == 1 && !(p = ft_strjoin(t[fd], "\n"))))
			return (-1);
	free(t[fd]);
	t[fd] = p;				// recurtion.
	return ((l > 0) ? get_next_line(fd, line) : 0);
}
