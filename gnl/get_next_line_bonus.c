/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/25 15:21:33 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



		// OK so this is the bonus, but now i need to addapt it to be not bonus which means possibly changing the algorythm...


#include "get_next_line_bonus.h"

char			*ft_strnew(size_t size)		// somehow combine bzero and strnew ???
{
	size_t	a;
	char	*ret;

	a = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (a <= size)
	{
		ret[a] = '\0';
		++a;
	}
	return (ret);
}

static int		term(t_glst **lst, t_glst *elem)
{
	t_glst	*tmp;

	tmp = *lst;
	if (tmp->fd == elem->fd)
	{
		*lst = tmp->next;
		free(tmp);
	}
	else
	{
		while (tmp->next->fd != elem->fd)
			tmp = tmp->next;
		tmp->next = tmp->next->next;	// bridging the gap
		free(elem);						// or tmp i think???
	}
	return (0);
}

static int		gnl(char **l, char **s, t_glst **lst, t_glst *elem)
{
	ssize_t	i;
	char	*p;
	char	b[BUFFER_SIZE + 1];
	
	p = NULL;
	if ((i = ft_findchar(*s, '\n')) != -1)
	{
		if (!(*l = ft_strsub(*s, 0, (size_t)i++))
			|| (!(p = ft_strsub(*s, i, ft_strlen(*s) - (size_t)i))))
			return (-1);
		free(*s);
		*s = p;
		return (1);
	}
	ft_bzero(b, BUFFER_SIZE + 1);
	if ((i = read(elem->fd, b, BUFFER_SIZE)) < 0
		|| (i > 0 && !(p = ft_strjoin(*s, b)))
		|| (*s[0] && ++i == 1 && !(p = ft_strjoin(*s, "\n"))))
		return (-1);
	free(*s);
	*s = p;
	return ((i > 0) ? gnl(l, s, lst, elem) : term(lst, elem));
}

int				get_next_line(int fd, char **line)
{
	static t_glst	*lst = NULL;
	t_glst			*new_elem;
	t_glst			*tmp;

	tmp = lst;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (tmp)
	{
		if (tmp->fd == fd)
			return (gnl(line, &tmp->s, &lst, tmp));
		tmp = tmp->next;
	}
	if (!(new_elem = (t_glst*)malloc(sizeof(t_glst))))
		return (-1);
	new_elem->fd = fd;
	new_elem->s = ft_strnew(1);
	new_elem->next = lst;
	lst = new_elem;
	return (gnl(line, &new_elem->s, &lst, new_elem));
}
