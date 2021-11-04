#include "get_next_line.h"

char	*get_line(char *readstr, char *r_main)
{
	//TODO gets line and saves remainder;
}

char	*read_data(int fd, char *r_main)
{
	char		BUFF[BUFFER_SIZE + 1];
	char		*readstr;
	int			b_read;

	b_read = 1;
	readstr = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF);
		if (ft_strchr(readstr, '\n'))
			return (get_line(readstr, r_main));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*r_main;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (fd >= 0 && fd <= 1024 && BUFFER_SIZE > 0)
	{
		if (ft_strchr(r_main, '\n'))
			return (get_line(r_main, NULL));
		return (read_data(fd, r_main));
	}
	return (NULL);
}

/**
 * 
*/