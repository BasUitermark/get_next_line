#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	FILE	*fp;
	int		fd;
	char	*filepath;
	size_t	i;
	char	*line;

	i = 0;
	filepath = "./test/empty.txt";
	// filepath = "./test/test1.txt";
	remove("./test/check.txt");
	fp = fopen("./test/check.txt", "w+");
	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		fprintf(fp, "%s", line);
		free(line);
		line = get_next_line(fd);
	}
	fprintf(fp, "%s", line);
	free(line);
	fclose(fp);
	close (fd);
	system("leaks a.out");
	return 0;
}

dit is dus zin 1
dit is dus zin 2

out: dit is dus zin 1
remainder = dit
