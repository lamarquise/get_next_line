/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:05:52 by erlazo            #+#    #+#             */
/*   Updated: 2020/02/06 18:32:27 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	b[BUFFER_SIZE + 1];
	int			i;

	if (!line || fd < 0)		// read check ???
		return (-1);
	i = ft_findchar(b, '\n');
	if (!(*line = ft_strsub(b, 0, (size_t)i)) || !ft_memmove(b, &b[i + 1], BUFFER_SIZE - i))
		return (-1);
	if (i != -1)	// for now
		return (1);
	while (
	


}


