/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2020/02/07 18:37:11 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	b[BUFF_SIZE + 1];

	p = NULL;
	if ((i = ft_findchar(*s, DELIM)) != -1)
	{
		if (!(*l = ft_strsub(*s, 0, (size_t)i++))
			|| (!(p = ft_strsub(*s, i, ft_strlen(*s) - (size_t)i))))
			return (-1);
		free(*s);
		*s = p;
		return (1);
	}
	ft_bzero(b, BUFF_SIZE + 1);
	if ((i = read(elem->fd, b, BUFF_SIZE)) < 0
		|| (i > 0 && !(p = ft_strjoin(*s, b)))
		|| (*s[0] && ++i == 1 && !(p = ft_strjoin(*s, "\n"))))
		return (-1);
	free(*s);
	*s = p;
	return ((i > 0) ? gnl(l, s, lst, elem) : term(lst, elem));
}

int				get_next_line(const int fd, char **line)
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
