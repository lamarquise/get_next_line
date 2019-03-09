/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/09 18:57:22 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>



	// need to test if my list actually deletes, does it free and all that... are there any leaks ???
	// that should be it tho.





#include "get_next_line.h"

static int		gnl(char **l, char **s, int fd, t_glst **lst, t_glst *elem)	// keep fd?
{
	int		i;
	char	*p;
	char	b[BUFF_SIZE + 1];
	t_glst	*tmp;

//	printf("test1\n");

	p = NULL;
	if ((i = ft_findchar(*s, DELIM)) != -1)
	{
//		printf("cut\n");
		if (!(*l = ft_strsub(*s, 0, i++)) || (!(p = ft_strsub(*s, i, ft_strlen(*s) - i))))
			return (-1);
		free(*s);
		*s = p;
		return (1);
	}
	ft_bzero(b, BUFF_SIZE + 1);
//	printf("test2\n");
	if ((i = read(fd, b, BUFF_SIZE)) < 0 || (i > 0 && !(p = ft_strjoin(*s, b))) ||
		(*s[0] && ++i == 1 && !(p = ft_strjoin(*s, "\n"))))
		return (-1);
	free(*s);
	*s = p;		// need to define p.
//	printf("pre final\n");
	if (i == 0 && *s == NULL)		// so this never happens...
	{
		tmp = *lst;
		if (tmp->fd == fd)
		{
			*lst = tmp->next;
			free(tmp);
		}
		else
		{
			while (tmp->next->fd != fd)
				tmp = tmp->next;
			tmp->next = tmp->next->next;
			free(elem);
		}
	}



/*
//		printf("final1\n");
		if (!e->prev)			// ok may need that start thing, might also be worth looking at my libft
			
		if (e->prev && e->next)
			e->prev->next = e->next;
//		printf("final2\n");
		free(e);
//		printf("final3\n");
	}
//	printf("post final\n");
*/	return ((i > 0) ? gnl(l, s, fd, lst, elem) : 0);
}


int		get_next_line(const int fd, char **line)		// 
{
	static t_glst	*lst = NULL;
	t_glst			*new_elem;
	t_glst			*tmp;

	tmp = lst;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (tmp)
	{
		if (tmp->fd == fd)
			return (gnl(line, &tmp->s, fd, &lst, tmp));
		tmp = tmp->next;
	}
	if (!(new_elem = (t_glst*)malloc(sizeof(t_glst))))		// can't really use the lib since its for lsts not glsts....
		return (-1);
	new_elem->fd = fd;
	new_elem->s = ft_strnew(1);
//	new_elem->l = 1;					// could get rid of ???
//	new_elem->prev = NULL;
	new_elem->next = lst;
//	if (lst)
//		lst->prev = new_elem;
	lst = new_elem;
	new_elem->start = lst;
	return (gnl(line, &new_elem->s, fd, &lst, new_elem));
}













