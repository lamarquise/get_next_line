/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/12/03 21:00:54 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line_2(int fd, char **line)
{
	ssize_t			i;
	static char		b[BUFFER_SIZE + 1] = "";
	char			*p;
	int				c;

//	printf("test1\n");

	p = NULL;
	if ((i = ft_findchar(*line, '\n')) != -1)
	{
		printf("line: %s\n", *line);
		if (!(p = ft_strsub(*line, 0, (size_t)i++)))
//			|| (!(b = ft_strsub(*line, i, ft_strlen(*line) - (size_t)i))))
			return (-1);
//		printf("findtests 1\n");
		c = 0;
		ft_bzero(b, sizeof(b));
//		printf("b:|%s|\n", b);
		while ((*line)[i] && c < BUFFER_SIZE)
		{
			b[c] = (*line)[i];
			printf("b: |%c| line: |%c|\n", b[c], (*line)[i]);
			i++;
			c++;
		}
		b[c] = '\0';
//		printf("b = %s\n", b);
//		printf("findtests 2\n");
//		printf("s after end of line %s\n", s);
		free(*line);
		*line = p;
		printf("line after cut: %s, b = |%s|\n", *line, b);
		return (1);
	}
//	printf("line = %s\n", *line);
//	printf("b = %s\n", b);
	if (!line /*|| !ft_bzero(b, sizeof(b))*/ 
		|| (!(*line)  && !(*line = ft_strsub(b, 0, ft_strlen(b))))		// is the condition not working ????
		|| (i = read(fd, b, BUFFER_SIZE)) < -1
		|| (i > 0 && !(ft_strjoin(line, b))) || i < 0)
		return (-1);

	if (i > 0)
		ft_bzero(b, sizeof(b));
//	if (b[0] && i == 0)
//		i = 1;
	
	printf("line pre appel: %s\n", *line);
	return ((i > 0 /*|| (ft_findchar(*line, '\n') != -1)*/) ? get_next_line_2(fd, line) : 0);
}

int			get_next_line(int fd, char **line)
{
	if (line)
		*line = NULL;
	return (get_next_line_2(fd, line));
}
