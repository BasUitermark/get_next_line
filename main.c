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
	filepath = "./test/test1.txt";
	remove("./test/check.txt");
	fp = fopen("./test/check.txt", "w+");
	fd = open(filepath, O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		fprintf(fp, "%s", line);
		free(line);
		i++;
	}
	fclose(fp);
	close (fd);
	// system("leaks a.out");
	return 0;
}
