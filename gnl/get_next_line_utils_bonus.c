/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:21:58 by erlazo            #+#    #+#             */
/*   Updated: 2020/01/21 17:42:40 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strsub(char *s, unsigned int start, size_t len)
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
	return (ret);
}

int		ft_bzero(void *s, size_t n)
{
	unsigned int	a;
	unsigned char	*str;

	a = 0;
	str = s;
	while (a < n)
	{
		str[a] = '\0';
		++a;
	}
	return (1);
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		a;
	char	*ret;
	int		c;

	if (!s1 && !s2)			// something else too ??? !*s1 ???
		return (NULL);
	a = ft_strlen(*s1) + ft_strlen(s2) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * a)))
		return (NULL);
	ft_bzero(ret, a);
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
	if (*s1 && **s1)			// not convinced this is safe enough ....
//	{
//		ft_bzero(*s1, ft_strlen(*s1));
		free(*s1);
//	}
	return (ret);
}
