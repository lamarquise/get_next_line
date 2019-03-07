/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/06 17:17:13 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>		// delete this line

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*tab[1000000];
	char	buff[BUFF_SIZE + 1];
	int		len;
	char	*tmp;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || (!tab[fd] && !(tab[fd] = ft_strnew(1))))
		return (-1);
	len = ft_findchar(tab[fd], DELIM);
	if (len != -1)
	{
		if (!(*line = ft_strsub(tab[fd], 0, len)) || !(tmp = ft_strsub(tab[fd], len + 1, (ft_strlen(tab[fd]) - (len + 1)))))
			return (-1);
		free(tab[fd]);
		tab[fd] = tmp;
		return (1);
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	if ((len = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	if (len > 0)
	{
		if (!(tmp = ft_strjoin(tab[fd], buff)))
			return (-1);
		free(tab[fd]);
		tab[fd] = tmp;
	}
	else if (len == 0 && tab[fd][0] != '\0' && ft_strlen(tab[fd]) > 0 && tab[fd][ft_strlen(tab[fd]) - 1])
	{
		len = 1;
		if (!(tmp = ft_strjoin(tab[fd], "\n")))
			return (-1);
		free(tab[fd]);
		tab[fd] = tmp;
	}
	if (len > 0)
		return (get_next_line(fd, line));
	return (0);
}



