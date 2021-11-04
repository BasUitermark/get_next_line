#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	FILE	*fp;
	int		fd;
	size_t	i;

	i = 0;
	remove("./test/test1check.txt");
	fp = fopen("./test/test1check.txt", "w+");
	fd = open("./test/test1.txt", O_RDONLY);
	while (i < 1)
	{
		fprintf(fp, "%s", get_next_line(fd));
		i++;
	}
	fclose(fp);
	close (fd);
	while(1);
	return 0;
}
