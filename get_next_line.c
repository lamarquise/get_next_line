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

static int		gnl(char **line, char **save, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		len;
	char	*tmp;

//	printf("test1\n");

	len = ft_findchar(*save, DELIM);
	
//	printf("pos: %i ", len);
//	printf("save: %s\n", *save);

	if (len != -1)		//!= -1 meaning there is a \n somewhere...
	{
//		printf("cut\n");

		if (!(*line = ft_strsub(*save, 0, len)))
			return (-1);
		if (!(tmp = ft_strsub(*save, len + 1, ft_strlen(*save))))
			return (-1);
		free(*save);
		*save = tmp;

//		printf("line: %s\n", *line);
//		printf("cut save: %s|\n", *save);
		return (1);
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	if ((len = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	if (len > 0)	//something was read.
	{
//		printf("save: %s\n", *save);
		
		if (!(tmp = ft_strjoin(*save, buff)))
			return (-1);
//		printf("test2\n");
		free(*save);
		*save = tmp;
//		printf("save: %s\n", *save);
	}
	else if (len == 0 && *save[0] != '\0')		// you need a more elegant solution...
	{
		len = 1;
		if (!(tmp = ft_strjoin(*save, "\n")))
			return (-1);
//		free(*save);
		*save = tmp;
	}
	if (len > 0) // something was read.
		return (gnl(line, save, fd));

	free(*save);		// i guess...
	return (0); // i think....
}

int		get_next_line(const int fd, char **line) // need basic checks prolly
{
	static char	*tab[1000000];				// it's static, should be fine when prog ends, no need for free...
	int			ret;

//	*line = ft_strnew(0);		// ok so this didn't fix as much as i would have liked...

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!tab[fd] && !(tab[fd] = ft_strnew(1)))
		return (-1);
//	printf("test1\n");
	
//	if (!tab[fd])		// no dif with below version
//		tab[fd] = ft_strnew(0);


//	if (!tab[fd] && !(tab[fd] = ft_strnew(0)))	// strnew of 0 ... very interesting
//		return (-1);
	
	ret = gnl(line, &tab[fd], fd);
	
//	if (ret == 0)
//		free(tab[fd]);
	return (ret);
}







