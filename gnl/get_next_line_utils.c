/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:21:58 by erlazo            #+#    #+#             */
/*   Updated: 2020/02/07 17:26:22 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>		// REMOVE !!!!!!!

#include "get_next_line.h"


			// what do i remove to make room for this ????
			// modify the join ???? perhaps....

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	if ((!dst && !src) || dst == src)
		return (dst);		// was NULL
	if ((int)dst - (int)src < 0)
	{
		a = -1;
		while (++a < len)
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
	}
	else
	{
		a = len;
		while (a-- > 0)
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
	}
	return (dst);
}




size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s && s[a])		// should i do an if around cuz better for number of operations
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

//	printf("join test 1\n");

	ret = NULL;
	
	if ((!s1 || !*s1) && !s2)
		return (NULL);
	a = 1;
	a = ft_strlen(*s1) + ft_strlen(s2) + 1;
//	printf("join test 1, i = %d\n", a);
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
//	if (*s1 && **s1)			// not convinced this is safe enough ....
	if (s1 && *s1)
	{
//		ft_bzero(*s1, ft_strlen(*s1));
		free(*s1);
	}
	return (ret);
}
