#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int		fd;
	char	*gnl;

	fd = open("./test_files/test1.txt", O_RDONLY);
	gnl = get_next_line(fd);
	printf("%s\n", gnl);

	close (fd);
	return 0;
}
