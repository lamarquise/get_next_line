/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:21:51 by erlazo            #+#    #+#             */
/*   Updated: 2020/01/30 17:24:31 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	if (ac == 1)
	{
		while ((ret = get_next_line(0, &str)) == 1)
		{
			ft_putendl(str);
			free(str);
		}
	}
	if (ac == 2)
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			while ((ret = get_next_line(fd, &str)) == 1)
			{
				ft_putendl(str);
				free(str);
			}
			close(fd);
			++i;
		}
	}
	if (ac > 2)					// ok so it's not perfect but it proves the point that the multi fd works all at the same time.
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
