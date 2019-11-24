/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/22 17:28:29 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	// ok so i don't free s but it might still work...

int				get_next_line(int fd, char **line)
{
	static char		*s = "\0";
	ssize_t			i;
	char			b[BUFFER_SIZE + 1];
	char			*p;
	
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
	ft_bzero(b, BUFFER_SIZE + 1);
	if ((i = read(fd, b, BUFFER_SIZE)) < 0
		|| (i > 0 && !(p = ft_strjoin(s, b)))
		|| (s[0] && ++i == 1 && !(p = ft_strjoin(s, "\n"))))		// why \n here ???
		return (-1);
//	free(s);					// seems like this fucked everyting up if *s isnt set to NULL
	s = p;
	return ((i > 0) ? get_next_line(fd, line) : 0);		// if 0 free s ???
}

