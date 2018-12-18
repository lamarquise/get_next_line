/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:51 by erlazo            #+#    #+#             */
/*   Updated: 2018/12/18 22:18:59 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>			// delete this line !!!!!!!!!!!!!!!



#include "get_next_line.h"

static char		*join(char *s1, char *s2, int len)
{
	char	*tmp1;
	char	*tmp2;
	
	tmp1 = s1;
	if (!(tmp2 = ft_strsub(s2, 0, len)))
		return (NULL);
	if (!(tmp1 = ft_strjoin(s1, tmp2)))
		return (NULL);
	free(tmp2);
	return (tmp1);
}
							// double pointer ???
static char		*parse(char **save)													// needs to be fixed, what if after the first \n there are char and then another \n
{
	char	*ret;
	char	*tmp;
	int		i;
	int		c;


//	printf("save1: %s\n", *save);
	c = 0;													// need to get rid of pre \n's like if the file starts with them...
	i = ft_findchar(*save, DELIM);			// so definitly don't want the + 1
//	c = i;
/*	if (i == 0)
	{
		while ((*save)[i] && (*save)[i] == DELIM)
			++i;
		if (!(ret = ft_strsub(*save, i, ft_strlen(*save))))
			return (NULL);
		*save = ret;
		free(ret);
		i = ft_findchar(*save, DELIM);
	}
*/	if (i != -1)
	{
		if (!(ret = ft_strsub(*save, 0, i)))					// wait fuck what if there's no \n, we get a -1 ....
			return (NULL);
//	c = 0; that's why it was segfaulting, you forgot to add this back...
		if (!(tmp = ft_strnew(BUFF_SIZE)))			// here we change save to be just the end after \n's
			return (NULL);
		while ((*save)[i] == DELIM)								// am i risking leaks by moving pinter?
			++i;
		while ((*save)[i])
			tmp[c++] = (*save)[i++];
		free(*save);								// it really doen't like this free for some reason....
	
//	printf("tmp after cut: %s\n", tmp);
	
		*save = tmp;

//	printf("save2: %s\n", *save);

		return (ret);
	}
	return (NULL);
}

static int		gnl(t_gnllst *elem)					// i think i have to parse in here.
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	
	while (ft_findchar(elem->save, DELIM) == 0)
	{
		if (!(tmp = ft_strsub(elem->save, 1, ft_strlen(elem->save))))
			return (-1);
		free(elem->save);
		elem->save = tmp;
	}
	if (ft_findchar(elem->save, DELIM) == -1)
	{
//		printf("rec test\n");
														// change this ret a bit, if it's 0 don't just return, see if can go further...
		if ((elem->len = read(elem->fd, buff, BUFF_SIZE)) <= 0)		// ok so it has to be a number thing, like i fucked up counting i or something
			return (elem->len);												// fix the 2
		if (!(tmp = join(elem->save, buff, BUFF_SIZE + 1)))
			return (-1);
		free(elem->save);
		elem->save = tmp;
		ft_strclr(buff);
		if (elem->len < BUFF_SIZE)			// possibly add another condition 
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
		if (tmp->fd == fd)
		{
			
			ret = gnl(tmp);
//			printf("pre ret: %i\n", ret);
			
//			printf("elem save: %s\n", tmp->save);

			*line = parse(&tmp->save);
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
	ret = gnl(new_elem);
//	printf("new elem save: %s\n", new_elem->save);
	*line = parse(&new_elem->save);
	return (ret);
}
