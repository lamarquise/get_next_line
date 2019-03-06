

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
	str = NULL;
	if (ac >= 2)
	{
//		printf("pre test1\n");
		while (i < ac)
		{
//			printf("test2\n");
			fd = open(av[i], O_RDONLY);
			
//			printf("fd: %i\n", fd);

			while ((ret = get_next_line(fd, &str)) == 1)
			{
		//		printf("pre test2\n");
				printf("%s\n", str);
//				ft_putendl(str);
				free(str);
			}
			close(fd);
			++i;
		}
	}
	return (0);
}
