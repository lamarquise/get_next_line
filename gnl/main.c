/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:21:51 by erlazo            #+#    #+#             */
/*   Updated: 2020/10/28 17:15:42 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_putendl(char const *s)
{
	int		a;

	a = 0;
	if (!s)
		return ;
	while ((char)s[a])
	{
		write(1, (void*)&s[a], 1);
		++a;
	}
	write(1, "\n", 1);
}

void	ft_putstr(char *s)
{
	int		a;

	a = 0;
	if (!s)
		return ;
	while (s[a])
	{
		write(1, &s[a], 1);
		++a;
	}
}


int		main(int ac, char **av)
{
	int		tab[ac - 1];
	int		i;
	int		fd;
	char	*str;
	int		ret;

	ret = 1;
	i = 1;
	str = NULL;
	if (ac == 1)		// Standard Output
	{

		ret = get_next_line(-4, &str);
	
		printf("ret %d\n", ret);	

		ft_putendl(str);
		free(str);

/*		while ((ret = get_next_line(0, &str)) == 1)
		{
			ft_putendl(str);
			free(str);
		}
		free(str);
*/	}
	if (ac == 2)		// 1 file
	{
		while (i < ac)
		{
//			printf("test 1\n");
			fd = open(av[i], O_RDONLY);
//			printf("test 2\n");
			while ((ret = get_next_line(fd, &str)) == 1)
			{
//				printf("test 3\n");
				printf("|%d|%s~\n", ret, str);
				free(str);
			}
			printf("|%d|%s~\n", ret, str);
			free(str);
			ret = get_next_line(fd, &str);
			printf("== After EOF gnl called again ==\n|%d|%s~\n", ret, str);
			free(str);
			close(fd);
			++i;
		}
//		printf("test final\n");
	}
	if (ac > 2)			// Multiples files
	{
		while (i < ac)
		{
			tab[i - 1] = open(av[i], O_RDONLY);
			++i;
		}
		i = 1;
		while (i < ac)
		{
			if (tab[i - 1] != -1 && (ret = get_next_line(tab[i - 1], &str)) == 1)
			{
		//		ft_putstr(str);
				ft_putendl(str);
				free(str);
			}
			else if (tab[i - 1] != -1 && (ret = get_next_line(tab[i - 1], &str)) != 1)
			{
				close (tab[i - 1]);
				tab [i - 1] = -1;
			}
			if (i < ac - 1)
				++i;
			else if (tab[ac - 2] == -1)
				i = ac;
			else
				i = 1;
		}
	}
	return (0);
}
