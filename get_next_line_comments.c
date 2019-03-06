/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/06 16:14:12 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>		// delete this line

#include "get_next_line.h"

// ok so if ever find a \n ret everything before, if only \n then that means ret a null pointer i guess, copy all starting right after first \n


// basically the only thing i care about is managing the \n, everything else should be pretty easy...
// if i consistently cut and save everything after the first \n, then im sittin pretty...
// it does seem a lot easier with a list...


static int		gnl(char **line, char **save, int fd)	// make it recursive with condition save is there ???
{
	char	buff[BUFF_SIZE + 1];
	int		len;
	char	*tmp;

	printf("test1\n");

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
		return (1);		// may be the best we're going to get
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	if ((len = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	
//	printf("read stuff\n");
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
	else if (len == 0 && *save[0] != '\0')
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

/*
	if (len == 0 && *save[0] != '\0')	//ok it's logical, glad i found this but it's still gross...
	{
//		printf("in in\n");
		len = 1;
		if (!(tmp = ft_strjoin(*save, "\n")))
			return (-1);
		free(*save);		// do i need to define another way to get ret 0 ???
		*save = tmp;
	}
	else if (len == 0 && *save[0] == '\0')		//memdel ???
	{
//		free(save);		// this fucks everything up but not the source of strange seg faults
		free(*line);		// this seems to have pretty much no effect... wait may actually be useful...
	}
	return ((len > 0) ? 2 : 0);		// there may be some cases im not thinking of...
*/
}





int		get_next_line(const int fd, char **line) // need basic checks prolly
{
	static char	*tab = NULL;
//	static char	*tab[1000];				// it's static, should be fine when prog ends, no need for free...
	int			ret;

//	*line = ft_strnew(0);		// ok so this didn't fix as much as i would have liked...

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!tab && !(tab = ft_strnew(0)))
		return (-1);
//	printf("test1\n");
	
//	ret = 2;


//	if (!tab[fd])		// no dif with below version
//		tab[fd] = ft_strnew(0);


//	if (!tab[fd] && !(tab[fd] = ft_strnew(0)))	// strnew of 0 ... very interesting
//		return (-1);
	
	ret = gnl(line, &tab, fd);
	
//	if (ret == 0)
//		free(tab[fd]);
	return (ret);

/*
	while (ret > 1)		//ret = 2 until gets to a \n, which could be artificial...
	{
		ret = gnl(line, &tab[fd], fd);
//		printf("tab: %s\n", tab[fd]);
	}
//	if (ret <= 0)			// that seems like it would work, especially given my main...
//		free(tab[fd]);
//	printf("end\n");
	return (ret);
*/
}


// Ok so this proved a point but it's not really all that useful...

/*

int		get_next_line(const int fd, char **line)
{
	static t_gnllst		*lst;
	t_gnllst			*new_elem;
	t_gnllst			*tmp;
	int					ret;

	tmp = lst;
	ret = 2;
	if (!(*line = ft_strnew(0)))
		return (-1);
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			while (ret > 1)
				ret = gnl(line, &tmp->save, fd);
			return (ret);
		}
		tmp = tmp->next;
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return (-1);

	printf("new elem\n");

	new_elem->fd = fd;
	new_elem->save = ft_strnew(0);
	new_elem->len = 1;
	new_elem->next = lst;
	lst = new_elem;
	
	while (ret > 1)
		ret = gnl(line, &new_elem->save, fd);
	return (ret);
}
*/
