/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:00:08 by erlazo            #+#    #+#             */
/*   Updated: 2019/02/17 12:24:00 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ok so if ever find a \n ret everything before, if only \n then that means ret a null pointer i guess, copy all starting right after first \n






static int		gnl(t_gnllst *elem)
{
	char	buff[BUFF_SIZE + 1];

	ft_bzero(buff, BUFF_SIZE + 1);
	if ((elem->len = read(elem->fd, buff, BUFF_SIZE)) < 0)
		return (-1);

}



















int		get_next_line(const int fd, char **line)
{
	static t_gnllst		*lst;
	t_gnllst			*new_elem;
	t_gnllst			*tmp;

	tmp = lst;
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (tmp)
	{
		//things including ret 1 or -1 or 0 maybe...
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return(-1);
	// create new elem...

//	return (0);
}
