/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:21:58 by erlazo            #+#    #+#             */
/*   Updated: 2019/12/03 21:00:57 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s && s[a])
		++a;
	return (a);
}

int		ft_findchar(char *str, char c)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

	// ok heres an idea, add a second string var to sub, if it's null then
	// return a malloced string
	// if it has something, then fill it with s but no malloc

char	*ft_strsub(char *s, unsigned int start, size_t len)		// could use better substr from new lib...
{
	unsigned int	a;
	char			*ret;

	a = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (a < len)
	{
		ret[a] = s[start + a];
		++a;
	}
	ret[a] = '\0';
//	printf("ret dans sub: |%s|\n", ret);
	return (ret);
}

int		ft_bzero(void *s, size_t n)		// could be better ????
{
	unsigned int	a;
	unsigned char	*str;

	a = 0;
	str = s;		// necessary??? I think so, for it to be casted ?
	while (a < n)
	{
		str[a] = '\0';
		++a;
	}
	return (1);
}

int		ft_strjoin(char **s1, char *s2)
{
	int		a;
	char	*ret;
	int		c;

	if (!s1 && !s2)			// was ||
		return (0);
	a = ft_strlen(*s1) + ft_strlen(s2) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * a)))
		return (0);
	ft_bzero(ret, a);			// changed form a to a -1
	a = 0;
	c = 0;
	while (*s1 && (*s1)[c])
	{
		ret[a++] = (*s1)[c];
		++c;
	}
	while (s2 && *s2)
	{
		ret[a++] = *s2;
		++s2;
	}
	ret[a] = '\0';
//	ft_bzero(*s1, ft_strlen(*s1));		// not necessary i think
//	if (*s1 && **s1)
	free(*s1);
	*s1 = ret;
	return (1);
}
