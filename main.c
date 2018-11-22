

	// Do not submit this file !!!!!!!!!!!

#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;
	int		iter;

	i = 1;
	if (ac >= 3)
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			iter = atoi(av[1]);
			while (iter > 0)
			{
				printf("Ret: %i\nLine: %s\n", get_next_line(fd, &str), str);
				--iter;
			}
			++i;
		}
	}
	return (0);
}
