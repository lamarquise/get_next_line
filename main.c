

	// Do not submit this file !!!!!!!!!!!

#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;
	int		ret;

//	printf("test0\n");
	ret = 1;
	i = 1;
	if (ac >= 2)
	{
//		printf("test1\n");
		while (i < ac)
		{
//			printf("test2\n");
			fd = open(av[i], O_RDONLY);
			
//			printf("fd: %i\n", fd);

			while (ret == 1 || ret == 2)
			{		
//				printf("test3\n");
				ret = get_next_line(fd, &str);
				printf("ret: %i str: %s\n", ret, str);
				free(str);
			}
			++i;
		}
	}
	return (0);
}
