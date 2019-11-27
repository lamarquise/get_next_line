/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:21:15 by erlazo            #+#    #+#             */
/*   Updated: 2019/11/27 17:05:53 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a])
		++a;
	return (a);
}

int		ft_findchar(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	if (!s || !(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (a < len)
	{
		ret[a] = (char)s[start + a];
		++a;
	}
	ret[a] = '\0';
	return (ret);
}

void	ft_bzero(void *s, size_t n)		// could be better ????
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
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);		// why is it null again ???
	a = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * a)))
		return (0);
	ft_bzero(ret, a);
	a = 0;
	while (*s1)
	{
		ret[a++] = *s1;
		++s1;
	}
	while (*s2)
	{
		ret[a++] = *s2;
		++s2;
	}
	return (ret);
}
