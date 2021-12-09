/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me <erlazo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:56:33 by me                #+#    #+#             */
/*   Updated: 2021/12/09 15:35:03 by erlazo           ###   ########.fr       */
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


#include <stdio.h>
#include <stdlib.h>	// for malloc
// for open
//#include unistd.h? for read
#include <unistd.h> // for read yes.


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
	while (i < n)
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
	i = 0;
	while (i < len)
	{
		ret[i] = str[start + i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	a;
	int	b;
	int	len;
	char *ret;

//	printf("start of join\n");
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
//	printf("join after got len\n");
	if (!(ret = malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(ret, len);
//	printf("join after malloc\n");
	a = 0;
	b = 0;
	while (s1 && s1[a])
	{
//		printf("join in first copy\n");
		ret[a] = s1[a];
		++a;
	}
	while (s2 && s2[b])
	{
//		printf("join in second copy\n");
		ret[a] = s2[b];
		++a;
		++b;
	}
	ret[a] = '\0';
	return (ret);
}

	// I think we are expecting Line to be NULL, but not sure, wish i had their mains...
	// pretty sure this is the prototype. It is.
//char	*gnl(int fd)
char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;	// may end up not using line, idk
	char		*p;
	char		buff[BUFFER_SIZE + 1];
	int			i;

//	printf("start of gnl\n");
	p = NULL;
	line = NULL;
		// look in extra bit for \n
	if ((i = ft_findchar(s, '\n')) != -1)
	{
		++i;
		if (!(line = ft_strsub(s, 0, i)))
			return (NULL);
		if (!(p = ft_strsub(s, i, ft_strlen(s) - i)))
			return (NULL);
		if (s)
			free(s);
		s = p;
		return (line);
	}
//	printf("gnl after look in end bit s\n");
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
		// ok maybe not null here cuz what if nothing left to read but stuff in s?
	i = read(fd, buff, BUFFER_SIZE);
//	printf("gnl right after read\n");
	if (i < 0)
		return (NULL);
	if (i == 0)
	{
		if (s)
			return (s);
		return (NULL);
	}
	if (i > 0)
	{
//		printf("gnl something was read\n");
		if (!(p = ft_strjoin(s, buff)))
		{
//			printf("gnl failed to join stuff\n");
			// prolly free stuff
			return (NULL);
		}
//		printf("gnl after join\n");
		if (s)
			free(s);
		s = p;
//		printf("gnl right before recursive call\n");
		return (get_next_line(fd));
	}
	
	// yea ok i'm not sure anymore... what do i return?
	printf("end end of GNL, not sure we ever get here...\n");

	return (NULL);
}





