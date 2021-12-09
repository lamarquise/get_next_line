/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:56:33 by me                #+#    #+#             */
/*   Updated: 2021/12/09 09:50:55 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In many ways the is the clearest GNL i have ever written... if only there weren't
	// the norm...

// figure out which includes
// pretty sure i'm allowed to use write
// there is no norm in exam
// will try it recursively but IDK maybe iterative is best?

// you'll want a simple testing main, something that uses the STDIN, easier
	// or maybe the av is the fd. 0 for STDIN? i think yes.


#include <stdlib.h>	// for malloc
// for open
// for read


int	ft_findchar(char *str, char c)
{
	int	i;

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

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_bzero(void *s, int n)
{
	int i;
	char *str;

	if (!s)
		return (0);
	i = 0;
	str = s;
	while (a < n)
	{
		str[i] = '\0';
		++i;
	}
	return (1);
}

char	*ft_strsub(char *str, int start, int len)
{
	int		i;
	char 	*ret;

	if (!str)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ret[i] = str[start + i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char s2)
{
	int	a;
	int	b;
	int	len;
	char *ret;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(ret, len);
	a = 0;
	b = 0;
	while (s1 && s1[a])
	{
		ret[a] = s1[a];
		++a;
	}
	while (s2 && s2[b])
	{
		ret[a] = s1[b];
		++a;
		++b;
	}
	ret[a] = '\0';
	return (ret);
}

	// I think we are expecting Line to be NULL, but not sure, wish i had their mains...
	// pretty sure this is the prototype. It is.
char	*gnl(int fd)
{
	static char	*s;
	char		*line;	// may end up not using line, idk
	char		*p;
	char		buff[BUFFER_SIZE + 1];
	int			i;

	p = NULL;
	line = NULL;
		// look in extra bit for \n
	if ((i = ft_findchar(s, '\n')) != -1)
	{
		if (!(line = ft_strsub(s, 0, i)))
			return (NULL);
		++i;
		if (!(p = ft_strsub(s, i, ft_strlen(s) - i)))
			return (NULL);
		free(s);
		s = p;
		return (line);
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_bzero(b, BUFF_SIZE + 1);
		// ok maybe not null here cuz what if nothing left to read but stuff in s?
	if ((i = read(fd, b, BUFFER_SIZE)) < 0) // not sure could need to be -1...
		return (NULL);
	if (i > 0)
	{
		if (!(p = ft_strjoin(s, b)))
		{
			// prolly free stuff
			return (NULL);
		}
		if (s)
			free(s);
		s = p;
		return (gnl(fd));
	}
	
	// yea ok i'm not sure anymore... what do i return?
}





