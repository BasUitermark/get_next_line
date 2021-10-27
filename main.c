#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	size_t	i;
	char	*line;

	i = 0;
	fd = open("./test/test1.txt", O_RDONLY);
	while (i <= 2)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	close (fd);
	return 0;
}
