/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:51 by erlazo            #+#    #+#             */
/*   Updated: 2018/12/17 18:57:09 by erlazo           ###   ########.fr       */
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
static char		*parse(char *save)													// needs to be fixed, what if after the first \n there are char and then another \n
{
	char	*ret;
	char	*tmp;
	int		i;
	int		c;

	c = 0;
	i = ft_findchar(save, DELIM) + 1;			// so this is the line that we will return
	if (!(ret = ft_strsub(save, 0, i)))
		return (NULL);
	if (!(tmp = ft_strnew(BUFF_SIZE)))			// here we change save to be just the end after \n's
		return (NULL);
	while (save[i] == DELIM)								// am i risking leaks by moving pinter?
		++i;
	while (save[i])
		tmp[c++] = save[i++];
//	free(save);
	save = tmp;
	return (ret);
}
/*
		if (!(tmp = join(line, elem->save, i + 1)))			// + 1 i think...
			return (-1);
//		free(line);
		line = tmp;
		tmp = elem->save;
		if (!(elem->save = cut(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}

*/
static int		gnl(t_gnllst *elem)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (ft_findchar(elem->save, DELIM) == -1)
	{

		printf("rec test\n");

		if ((elem->len = read(elem->fd, buff, BUFF_SIZE)) <= 0)		// ok so it has to be a number thing, like i fucked up counting i or something
			return ((elem->len < 0) ? -1 : 2);												// fix the 2
		if (!(tmp = join(elem->save, buff, BUFF_SIZE + 1)))
			return (-1);
		free(elem->save);
		elem->save = tmp;
		return (gnl(elem));
	}
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
			
			*line = parse(tmp->save);

				// here we call the function that parses the string in the elem
			
			return (ret);
		}
		tmp = tmp->next;
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return (-1);
	new_elem->fd = fd;
	
//	printf("pre test1\n");

	new_elem->save = ft_strnew(1);
	new_elem->next = lst;
	lst = new_elem;
	ret = gnl(new_elem);
	*line = parse(new_elem->save);
	return (ret);
}
