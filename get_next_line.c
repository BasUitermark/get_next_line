#include "get_next_line.h"
/*
Read file from fd.
Read for BUFFER_SIZE amount of bytes at a time.

*/
char *get_next_line(int fd)
{
	char	*get;
	size_t	i;

	get = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!get)
		return (NULL);
	read(fd, get, BUFFER_SIZE);
	i = ft_strlen(get);
	get[i] = '\0';
	return (get);
}

