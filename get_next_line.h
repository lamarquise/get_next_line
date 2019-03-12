/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:59 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/11 19:08:57 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define DELIM '\n'
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
typedef struct	s_glst
{
	char			*s;
	int				fd;
	struct s_glst	*next;
	struct s_glst	*start;
}				t_glst;
int				get_next_line(const int fd, char **line);
#endif
