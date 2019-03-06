/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:51 by erlazo            #+#    #+#             */
/*   Updated: 2018/12/21 18:16:32 by erlazo           ###   ########.fr       */
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
//	if (!save || !*save)
//		return (NULL);
//	tmp = NULL;									// OOOORRRRRR \0 ......
/*	while (ft_findchar(*save, DELIM) == 0 && ft_strlen(*save) >= 1)
	{
		if (!(tmp = ft_strsub(*save, 1, ft_strlen(*save))))
			return (NULL);
		*save = tmp;
	}
*/	i = ft_findchar(*save, DELIM);
	if (i != -1)
	{
		if (!(ret = ft_strsub(*save, 0, i)))
			return (NULL);
		if (!(tmp = ft_strnew(ft_strlen(*save))))
			return (NULL);
		while ((*save)[i] == DELIM)
			++i;
		while ((*save)[i])									// could do a strsub instead but.... maybe later
			tmp[c++] = (*save)[i++];
		free(*save);
		*save = tmp;
	}
	else
	{
		if (!(ret = ft_strdup(*save)))
			return (NULL);
		free(*save);
		*save = ft_strnew(1);
	}
//	free(*save);
//	*save = tmp;
	return (ret);



/*
//	c = 0;
	i = ft_findchar(*save, DELIM);
	if (i != -1)
	{
		if (!(ret = ft_strsub(*save, 0, i)))
			return (NULL);
		while ((*save)[i] == DELIM)
			++i;
	}
	else											// dumbass, its the otherone if i == -1
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
*/
//	return (ret);
}

static int      gnl(t_gnllst *elem)			// almost have it working with buff = 1
{										// some trouble with other buff sizes tho
	char	buff[BUFF_SIZE + 1];
	char    *tmp;
	int		i;

	ft_bzero(buff, BUFF_SIZE + 1);
	i = 0;
	while (elem->save[i] && elem->save[i] == DELIM)
	{
		++i;
		printf("removing n's\n");
	}
	if (!(tmp = ft_strsub(elem->save, i, ft_strlen(elem->save))))	// should do \0 if all \n's
		return (-1);
	free(elem->save);
	elem->save = tmp;


/*	while (ft_findchar(elem->save, DELIM) == 0 && ft_strlen(elem->save) >= 1)
	{
		if (!(tmp = ft_strsub(elem->save, 1, ft_strlen(elem->save))))
			return (-1);
		elem->save = tmp;
	}
*/	if (ft_findchar(elem->save, DELIM) == -1 && elem->len != 0)		//second conditon necessary???
	{
//		printf("test\n");
		if ((elem->len = read(elem->fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (elem->len > 0)
		{
			if (!(tmp = ft_strjoin(elem->save, buff)))
				return (-1);
	//		ft_bzero(buff, BUFF_SIZE + 1);
			free(elem->save);
			elem->save = tmp;
		}
	}
	if (ft_findchar(elem->save, DELIM) <= 0 && elem->len == BUFF_SIZE)
		return (gnl(elem));
	if (elem->len == 0)
		return (0);

	printf("test end\n");

//	if (elem->len == BUFF_SIZE)
//		return (gnl(elem));

	
	
//	if (ft_findchar(elem->save, DELIM) > 0)
//		*line = parse(elem);
//	else if (!(*line = ft_strdup(elem->save)))
//		return (-1);
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
//		printf("list test\n");
		if (tmp->fd == fd)
		{
			
//			while (ft_findchar(tmp->save, '\0') == 0 && tmp->len > 0)	
				ret = gnl(tmp);
			if (tmp->len == 0)
				return (0);								// do i have to clear line if this happenes???
			*line = parse(&tmp->save);
			
//			printf("final test\n");

			return (ret);
		}
		tmp = tmp->next;
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return (-1);
	new_elem->fd = fd;
	
	printf("pre test1\n");

	new_elem->save = ft_strnew(1);
	new_elem->len = BUFF_SIZE;						// just to be safe...
	new_elem->next = lst;
	lst = new_elem;
//	while (ft_findchar(new_elem->save, '\0') == 0 && new_elem->len > 0)
//	{
		printf("len: %i\n", new_elem->len);	
		ret = gnl(new_elem);
//	}
	if (new_elem->len == 0)
		return (0);
	*line = parse(&new_elem->save);
	return (ret);
}
