/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:59 by erlazo            #+#    #+#             */
/*   Updated: 2020/10/28 16:34:06 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//# define BUFFER_SIZE = 42

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
int				ft_findchar(char *str, char c);
char			*ft_strsub(char *s, unsigned int start, size_t len);
int				ft_bzero(void *s, size_t n);
char			*ft_strjoin(char **s1, char *s2);

#endif
