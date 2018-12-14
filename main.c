

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

	i = 2;
	if (ac >= 3)
	{
//		printf("test1\n");
		while (i < ac)
		{
//			printf("test2\n");
			fd = open(av[i], O_RDONLY);
			
//			printf("fd: %i\n", fd);

			iter = atoi(av[1]);
			while (iter > 0)
			{		
//				printf("test3\n");
				printf("\nRet: %i\n", get_next_line(fd, &str));
				printf("str: %s\n", str);
				--iter;
			}
			++i;
		}
	}
	return (0);
}
