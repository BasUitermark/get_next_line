#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// int	main(int argc, char const *argv[])
// {
// 	int		fd;
// 	// size_t	i;
// 	// char	*line;

// 	// i = 0;
// 	fd = open("./test/test1.txt", O_RDONLY);
// 	while (get_next_line(fd))
// 	{
// 		printf("%s\n", get_next_line(fd));
// 	}
// 	close (fd);
// 	return 0;
// }

int	main(int argc, char const *argv[])
{
	int		fd;
	size_t	i;

	i = 0;
	fd = open("./test/test1.txt", O_RDONLY);
	while (i < 2)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	close (fd);
	return 0;
}
