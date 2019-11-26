/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:59 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/26 17:14:04 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_glst
{
	char			*s;
	int				fd;
	struct s_glst	*next;
}				t_glst;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
int				ft_findchar(char *str, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_bzero(void *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
