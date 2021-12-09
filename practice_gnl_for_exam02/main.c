

#include <stdio.h> // for printf
#include <unistd.h> // for read
#include <fcntl.h> // for open?
#include <stdlib.h> // for free?

char	*get_next_line(int fd);
int		ft_strlen(char *str);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int	i;
	int	fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (0);

	printf("pre gnl main\n");
	i = 0;
	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
//		printf("in gnl loop\n");
		write(1, line, ft_strlen(line));
//		printf("Line: |%s| end line\n", line);
	//	printf("in gnl loop\n");
		if (line)
			free(line);
//		printf("in gnl loop after free\n");
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (fd)
		close(fd);
	while (1)
	{

	}
	return (0);
}
