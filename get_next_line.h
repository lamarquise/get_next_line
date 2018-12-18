/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:59 by erlazo            #+#    #+#             */
/*   Updated: 2018/12/18 22:19:02 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1		//right spot???
# define DELIM '\n'			//do i need the ' ' ???`

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_gnllst
{
	char				*save;
	int					len;
	int					fd;
	struct s_gnllst		*next;
}				t_gnllst;

int				get_next_line(const int fd, char **line);

			// Prototypes for libft functions? or just the libft.h file in my return ???

#endif
