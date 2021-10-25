#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;

	fd = open("./test_files/test1.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close (fd);
	return 0;
}
