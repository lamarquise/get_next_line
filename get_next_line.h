/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:59 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/06 17:12:13 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2		//right spot???
# define DELIM '\n'			//do i need the ' ' ???`

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_glst
{
	char			*s;
	int				fd;
//	long			l;
	struct s_glst	*next;
	struct s_glst	*prev;
}				t_glst;

int				get_next_line(const int fd, char **line);

#endif
