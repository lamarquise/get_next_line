/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:51 by erlazo            #+#    #+#             */
/*   Updated: 2018/12/19 16:18:03 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>			// delete this line !!!!!!!!!!!!!!!



#include "get_next_line.h"

static char		*parse(char **save)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		c;

	c = 0;
	i = ft_findchar(*save, DELIM);
	if (i != -1)
	{
		if (!(ret = ft_strsub(*save, 0, i)))
			return (NULL);
		while ((*save)[i] == DELIM)
			++i;
	}
	else
		i = 0;
	if (!(tmp = ft_strnew(ft_strlen(*save))))			// here we change save to be just the end after \n's
		return (NULL);
//	while ((*save)[i] == DELIM)
//		++i;
	while ((*save)[i])
		tmp[c++] = (*save)[i++];
	free(*save);								// it really doen't like this free for some reason....
	
//	printf("tmp after cut: %s\n", tmp);
	
	*save = tmp;

//	printf("save2: %s\n", *save);

	return (ret);
}

static int		gnl(t_gnllst *elem, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	
	while (ft_findchar(elem->save, DELIM) == 0 && ft_strlen(elem->save) >= 1)
	{
		if (!(tmp = ft_strsub(elem->save, 1, ft_strlen(elem->save))))
			return (-1);
//		free(elem->save);						// doesn't like this free either... ????
		elem->save = tmp;
	}
	if (ft_findchar(elem->save, DELIM) == -1)
	{
//		printf("rec test\n");

		if ((elem->len = read(elem->fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (!(tmp = ft_strjoin(elem->save, buff)))
			return (-1);
		free(elem->save);
		elem->save = tmp;					// somewhere in here i need to be like if can keep reading, else make sure save is empty and then return line
	}
	*line = parse(elem->save);
//		ft_strclr(buff);
		if (elem->len < BUFF_SIZE || ft_findchar(buff, 10) >= 0)			// possibly add another condition 
			return (2);	
		return (gnl(elem));
	}
//	else if (ft_findchar(elem->save, 10) >= 0)
//		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)			// add checks to free here... i guess, or maybe in other func...
{
	static t_gnllst		*lst;
	t_gnllst			*new_elem;
	t_gnllst			*tmp;
	int					ret;
	
	tmp = lst;
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (tmp)														// if gnl func returns -1, should clear line, i think...
	{
		printf("list test\n");
		if (tmp->fd == fd)
		{
			
			ret = gnl(tmp, line);
//			printf("pre ret: %i\n", ret);
			
//			printf("elem save: %s\n", tmp->save);
//			if (ret != 2)
	//			*line = parse(&tmp->save);
//			else										// and  also terminate list
//				*line = tmp->save;						// im pretty sure there are not possibilities where this doesn't work, cuz 
//			if (ft_findchar(*line, 10) == 0)				// was trying to get it to return 0 when gets to end of file where there are only \n's, but i think it's fine
//				ret = 0;

//			if (ret == 2)
				// some sort of terminate thing...
//			printf("elem save2: %s\n", tmp->save);

		
			return (ret);
		}
		tmp = tmp->next;
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return (-1);
	new_elem->fd = fd;
	
	printf("pre test1\n");

	new_elem->save = ft_strnew(1);
	new_elem->next = lst;
	lst = new_elem;
	ret = gnl(new_elem, line);
//	printf("new elem save: %s\n", new_elem->save);
//	if (ret != 2)
	//	*line = parse(&new_elem->save);
//	else
//		*line = new_elem->save;			// and also the terminate list thing
	return (ret);
}
