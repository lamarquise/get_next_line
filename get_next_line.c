/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:51 by erlazo            #+#    #+#             */
/*   Updated: 2018/12/16 20:26:10 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>			// delete this line !!!!!!!!!!!!!!!



#include "get_next_line.h"

char	*cut(char *str)													// needs to be fixed, what if after the first \n there are char and then another \n
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_strnew(BUFF_SIZE)))
		return (NULL);
	str += ft_findchar(str, DELIM) + 1;
	while (*str == DELIM)								// yea kinda messy but it's fine...
		++str;
	while (*str)
	{
		ret[i++] = *str;
		++str;
	}
	return (ret);
}



	// ok so this takes the fd reads the file, allocates to the right places, sets line & elem right, 
	// and returns a failed or not value
	//we have room to add more error conditions, which should come in handy...

int		gnl(char **line, t_gnllst *elem)
{
	char	*buff;
	int		i;
	int		ch;

//	printf("test1\n");

	ch = 1;
	if ((i = ft_findchar(elem->save, DELIM)) != -1)									// so we return the part we want and set save to the reste, cool.
	{
		if (!(*line = ft_strjoin(*line, ft_strncpy(ft_strnew(i), elem->save, i))))
			return (-1);
		if (!(elem->save = cut(elem->save)))			// do i need a tmp so i can free things....
			return (-1);
		return (1);
	}
	if (!(*line = ft_strdup(elem->save)) || !(buff = ft_strnew(BUFF_SIZE)))			// at this point, elem->save has no \n for sure.
		return (-1);
	free(elem->save);		// or strclr ???
	while (ch)															// the while seems a bit out of place given my structure...
	{
		if ((elem->len = read(elem->fd, buff, BUFF_SIZE)) <= 0)
			return ((elem->len < 0) ? -1 : 0);
		if ((i = ft_findchar(buff, DELIM)) != -1)
		{
			if (!(*line = ft_strjoin(*line, ft_strncpy(ft_strnew(i), buff, i))))
				return (-1);
			if (!(elem->save = cut(buff)))
				return (-1);
			ch = 0;
		}
		else if (!(*line = ft_strjoin(*line, ft_strncpy(ft_strnew(elem->len), buff, elem->len))))
			return (-1);
	}
	ft_strdel(&buff);
	return (1);
}





		// THE OLD VERSION


/*

int		gnl( char **line, t_gnllst **elem)
{
	char	*buff;
	int		i;
	int		ch;

	ch = 1;
//	printf("save: %s\n", (*elem)->save);			// save is empty here for some reason.
	if (!(*line = ft_strdup((*elem)->save)) || !(buff = ft_strnew(BUFF_SIZE)))			// does this mean i have to free line everytime ... ???
		return (-1);
	free((*elem)->save);
	//	ft_strclr((*elem)->save);
	while (ch)
	{
//		printf("further test2\n");

//	ft_strclr((*elem)->save);
		if (((*elem)->len = read((*elem)->fd, buff, BUFF_SIZE)) <= 0)
			return (((*elem)->len < 0) ? -1 : 0);		// should say if failed or file ended


		i = ft_findchar(buff, DELIM);		// ok so this does work, its the next if that doesn't....
		if (i == -1)
			i = (*elem)->len; //BUFF_SIZE;		// + 1 ???
		

		if (!(*line = ft_strjoin(*line, ft_strncpy(ft_strnew((*elem)->len), buff, i))))		//switching i for BUFF_SIZE fixed end but not middle...
			return (-1);

		if (i < BUFF_SIZE || (*elem)->len < BUFF_SIZE)		// added the +1 might need some tweeking...
		{
			if (!((*elem)->save = cut(buff)))
				return (-1);
			ch = 0;
		}
		ft_bzero(buff, BUFF_SIZE + 1);				// necessary ???
	}
	ft_strdel(&buff);
	return (1);
}

*/


int		get_next_line(const int fd, char **line)			// add checks to free here... i guess, or maybe in other func...
{
	static t_gnllst		*lst;
	t_gnllst			*new_elem;
	t_gnllst			*tmp;
	
	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (gnl(line, tmp));
		tmp = tmp->next;
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return (-1);
	new_elem->fd = fd;
	
//	printf("pre test1\n");

	new_elem->save = ft_strnew(1);
	new_elem->next = lst;
	lst = new_elem;
	return (gnl(line, new_elem));
}
