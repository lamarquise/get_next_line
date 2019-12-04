/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/12/04 21:26:23 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		term(t_glst **lst, t_glst *elem)
{
	t_glst	*tmp;

	tmp = *lst;
	if (tmp->fd == elem->fd)
	{
		*lst = tmp->next;
		free(tmp->s);
		free(tmp);
	}
	else
	{
		while (tmp->next->fd != elem->fd)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
		free(elem->s);
		free(elem);
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
	if (!l || !ft_bzero(b, BUFFER_SIZE + 1)
		|| (i = read(elem->fd, b, BUFFER_SIZE)) < -1
		|| (i > 0 && !(p = ft_strjoin(s, b)))
		|| (*s && *s[0] && ++i == 1 && !(*l = ft_strjoin(s, "")))
		|| (i < 1 && !(*l) && !(*l = ft_strsub(NULL, 0, 0))) || i < 0)
		return (-1);
	if (i > 0)
		*s = p;
	return ((i > 0) ? gnl(l, s, lst, elem) : term(lst, elem));
}

int				get_next_line(int fd, char **line)
{
	static t_glst	*lst = NULL;
	t_glst			*new_elem;
	t_glst			*tmp;

	tmp = lst;
	if (line)
		*line = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (gnl(line, &tmp->s, &lst, tmp));
		tmp = tmp->next;
	}
	if (!(new_elem = (t_glst*)malloc(sizeof(t_glst))))
	{
		*line = ft_strsub(NULL, 0, 0);
		return (-1);
	}
	new_elem->fd = fd;
	new_elem->s = NULL;
	new_elem->next = lst;
	lst = new_elem;
	return (gnl(line, &new_elem->s, &lst, new_elem));
}
